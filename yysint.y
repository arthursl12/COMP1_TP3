%{
    #include <stdio.h>    
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "aux.h"
    #include "tab.h"

    #define YYDEBUG 1          /* Se ligado, imprime mais informações */

    /* Constantes para tipos */
    #define TYPE_INT    1
    #define TYPE_REAL   2
    #define TYPE_CHAR   3
    #define TYPE_BOOL   4

    /* Forward declaration de funções do Lex */
    void yyerror (char *s);
    void typeerror();
    int yylex();

    /* Globals da Tabela de Símbolos */
    extern int escopo[10];
    extern int nivel;      /* nível atual */
    extern int L;          /* índice do último elemento da tabela */
    extern int Raiz;   

    /* Funções Auxiliares da Tabela de Símbolos */
    void installIdentList(char* type);
    int novoVal = 1;       /* Global para testar o updateVal */
    void updateVal(char* id, char* value);
    int q = 0;              /* Tamanho do ident_list */
    char* id_list[20];      /* Lista de identificadores numa declaração */
%}

%union {
    int integer; 
    float real; 
    int boolean; 
    char character; 
    char* string; 

    /* Tipos de Não-terminais */
    struct expr { 
        int type; 
        union value value;
    } expr; 
}         /* Yacc definitions */



/* Tokens */
/* Tokens ADDOPs */
%token ADD OR           // + or
%token MINUS            // -
// Obs.: o analisador sintático decide se é a subtração ou o menos unário

/* Tokens RELOPs */
%token EQUALS NEQ       // = != 
%token LT GT LTE GTE    // < > <= >= 

/* Tokens MULOPs */
%token MULT DIV         // * /
%token IDIV MOD         // div mod
%token AND              // and

%token NOT
%token ASSIGN
%token <integer> INT_CONSTANT
%token <real> REAL_CONSTANT
%token <boolean> BOOL_CONSTANT
%token <string> IDENTIFIER
%token <string> IDENTIFIER_F       // Identificador de funções-padrão
%token <character> CHAR_CONSTANT

/* Tokens de Palavras Reservadas */
%token PROGRAM
%token <string> INTEGER REAL BOOLEAN CHAR
%token BEGIN_STMT END
%token IF THEN ELSE
%token DO WHILE
%token UNTIL
%token READ WRITE GOTO

/* Tokens de Funções Padrão */
%token SIN LOG COS
%token ORD CHR
%token ABS SQRT EXP
%token EOF_TOKEN EOLN

/* Símbolo de partida */
%start program

/* Associatividade e Precedência */
%left ADD OR MINUS MULT DIV IDIV MOD AND
%nonassoc EQUALS NEQ LT GT LTE GTE
%nonassoc THEN
%nonassoc ELSE

/* Tipos de alguns símbolos Não-terminais */
%type <string> type decl ident_list
%type <expr> constant factor factor_a expr simple_expr term
%type <expr> function_ref

%%

/* descriptions of expected inputs     corresponding actions (in C) */
    /* Header e Declarações */
program                 :   PROGRAM IDENTIFIER ';' decl_list compound_stmt 
decl_list               :   decl_list ';' decl              { q = 0; }
                        |   decl                            { q = 0; }
                        ;
decl                    :   ident_list ':' type             { installIdentList($3); $$ = $1; }
ident_list              :   ident_list ',' IDENTIFIER       { id_list[q] = $3; q++; }
                        |   IDENTIFIER                      { id_list[q] = $1; q++; }
                        ;
type                    :   INTEGER
                        |   REAL
                        |   BOOLEAN
                        |   CHAR
                        ;
    /* ----- Statements ----- */
compound_stmt           :   BEGIN_STMT stmt_list END
                        ;
stmt_list               :   stmt_list ';' stmt
                        |   stmt
                        ;
stmt                    :   label ':' unlabelled_stmt
                        |   unlabelled_stmt
                        ;
label                   :   IDENTIFIER 
                        ;
unlabelled_stmt         :   assign_stmt
                        |   if_stmt
                        |   loop_stmt
                        |   read_stmt
                        |   write_stmt
                        |   goto_stmt
                        |   compound_stmt
                        ;
assign_stmt             :   IDENTIFIER ASSIGN expr          
                            { 
                                // Pesquisa a entrada na tabela de símbolos
                                int res_niv;
                                int res_i;
                                Get_Entry($1, &res_niv, &res_i);

                                if (res_niv == -1){
                                    // Não encontrou na tabela
                                    exit(1);
                                }

                                if (TabelaS[res_i].type == TYPE_REAL 
                                    &&
                                    $3.type == TYPE_INT){
                                    // Pode colocar int em real
                                    TabelaS[res_i].value = $3.value;
                                }else if (TabelaS[res_i].type != $3.type){
                                    printf("IDType: %i\n", TabelaS[res_i].type);
                                    printf("ExprType: %i\n", $3.type);
                                    typeerror();
                                }else{
                                    TabelaS[res_i].value = $3.value;
                                }
                                // updateVal($1,"updt"); 

                            }
                        ;
cond                    :   expr
                        ;
if_stmt                 :   IF cond THEN stmt   %prec THEN
                        |   IF cond THEN stmt ELSE stmt
                        ;
loop_stmt               :   stmt_prefix DO stmt_list stmt_suffix
                        ;
stmt_prefix             :   WHILE cond
                        |   /* vazio */
                        ;
stmt_suffix             :   UNTIL cond
                        |   END
                        ;
read_stmt               :   READ '(' ident_list ')'
                        ;
write_stmt              :   WRITE '(' expr_list ')'
                        ;
goto_stmt               :   GOTO IDENTIFIER
                        ;
    /* ----- Expressões ----- */
expr_list               :   expr
                        |   expr_list ',' expr
                        ;
expr                    :   simple_expr
                            { 
                                $$.type = $1.type; 
                                $$.value = $1.value; 
                            }
                        |   simple_expr EQUALS simple_expr
                            { 
                                // Não importa os tipos dos operandos
                                $$.type = TYPE_BOOL; 
                            
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   simple_expr NEQ simple_expr
                            { 
                                // Não importa os tipos dos operandos
                                $$.type = TYPE_BOOL; 
                                
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   simple_expr LT simple_expr
                            { 
                                if ($1.type != TYPE_INT && $1.type != TYPE_REAL)
                                    typeerror();
                                else if ($3.type != TYPE_INT && $3.type != TYPE_REAL)
                                    typeerror();
                                
                                $$.type = TYPE_BOOL; 

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   simple_expr LTE simple_expr
                            { 
                                if ($1.type != TYPE_INT && $1.type != TYPE_REAL)
                                    typeerror();
                                else if ($3.type != TYPE_INT && $3.type != TYPE_REAL)
                                    typeerror();
                                
                                $$.type = TYPE_BOOL; 

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   simple_expr GT simple_expr
                            { 
                                if ($1.type != TYPE_INT && $1.type != TYPE_REAL)
                                    typeerror();
                                else if ($3.type != TYPE_INT && $3.type != TYPE_REAL)
                                    typeerror();
                                
                                $$.type = TYPE_BOOL; 

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   simple_expr GTE simple_expr
                            { 
                                if ($1.type != TYPE_INT && $1.type != TYPE_REAL)
                                    typeerror();
                                else if ($3.type != TYPE_INT && $3.type != TYPE_REAL)
                                    typeerror();
                                
                                $$.type = TYPE_BOOL; 

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        ;
simple_expr             :   term
                            { 
                                $$.type = $1.type; 
                                $$.value = $1.value; 
                            }
                        |   simple_expr ADD term
                            {
                                if (($1.type == TYPE_INT || $1.type == TYPE_REAL)
                                    &&
                                    ($3.type == TYPE_INT || $3.type == TYPE_REAL))
                                {
                                    // Estamos operando com números

                                    if ($1.type == TYPE_INT 
                                    && $3.type == TYPE_INT)
                                    {
                                        // Dois inteiros
                                        $$.type = TYPE_INT;
                                        // TODO: criar quádrupla para calcular valor
                                        // $$.value = $1.value; 
                                    }else{
                                        // Pelo menos um real
                                        $$.type = TYPE_REAL;
                                        // TODO: criar quádrupla para calcular valor
                                        // $$.value = $1.value; 
                                    }
                                }else
                                    typeerror();
                            }
                        |   simple_expr MINUS term
                            {
                                if (($1.type == TYPE_INT || $1.type == TYPE_REAL)
                                    &&
                                    ($3.type == TYPE_INT || $3.type == TYPE_REAL))
                                {
                                    // Estamos operando com números

                                    if ($1.type == TYPE_INT 
                                    && $3.type == TYPE_INT)
                                    {
                                        // Dois inteiros
                                        $$.type = TYPE_INT;
                                        // TODO: criar quádrupla para calcular valor
                                        // $$.value = $1.value; 
                                    }else{
                                        // Pelo menos um real
                                        $$.type = TYPE_REAL;
                                        // TODO: criar quádrupla para calcular valor
                                        // $$.value = $1.value; 
                                    }
                                }else
                                    typeerror();
                            }
                        |   simple_expr OR term
                            { 
                                if ($1.type == TYPE_BOOL 
                                    && $3.type == TYPE_BOOL){
                                    
                                    $$.type = TYPE_BOOL;
                                    // TODO: criar quádrupla para calcular valor
                                    // $$.value = $1.value; 
                                }else
                                    typeerror();
                            }   
                        ;
term                    :   factor_a
                            { 
                                $$.type = $1.type; 
                                $$.value = $1.value; 
                            } 
                        |   term MULT factor_a
                            { 
                                if (($1.type == TYPE_INT || $1.type == TYPE_REAL)
                                    &&
                                    ($3.type == TYPE_INT || $3.type == TYPE_REAL))
                                {
                                    // Estamos operando com números
                                    if ($1.type == TYPE_INT 
                                    && $3.type == TYPE_INT)
                                    {
                                        // Dois inteiros
                                        $$.type = TYPE_INT;
                                        // TODO: criar quádrupla para calcular valor
                                        // $$.value = $1.value; 
                                    }else{
                                        // Pelo menos um real
                                        $$.type = TYPE_REAL;
                                        // TODO: criar quádrupla para calcular valor
                                        // $$.value = $1.value; 
                                    }
                                }else
                                    typeerror();
                            } 
                        |   term DIV factor_a
                            { 
                                if (($1.type == TYPE_INT || $1.type == TYPE_REAL)
                                    &&
                                    ($3.type == TYPE_INT || $3.type == TYPE_REAL))
                                {
                                    $$.type = TYPE_REAL;
                                    // TODO: criar quádrupla para calcular valor
                                    // $$.value = $1.value; 
                                }else
                                    typeerror();
                            } 
                        |   term IDIV factor_a
                            { 
                                if ($1.type == TYPE_INT
                                    && $3.type == TYPE_INT)
                                {
                                    $$.type = TYPE_INT;
                                    // TODO: criar quádrupla para calcular valor
                                    // $$.value = $1.value; 
                                }else
                                    typeerror();
                            } 
                        |   term MOD factor_a
                            { 
                                if ($1.type == TYPE_INT 
                                    && $3.type == TYPE_INT){
                                    
                                    $$.type = TYPE_INT;
                                    // TODO: criar quádrupla para calcular valor
                                    // $$.value = $1.value; 
                                }else
                                    typeerror();
                            } 
                        |   term AND factor_a
                            { 
                                if ($1.type == TYPE_BOOL 
                                    && $3.type == TYPE_BOOL){
                                    
                                    $$.type = TYPE_BOOL;
                                    // TODO: criar quádrupla para calcular valor
                                    // $$.value = $1.value; 
                                }else
                                    typeerror();
                            }   
                        ;
function_ref            :   SIN '(' expr ')'
                            {
                                if ($3.type != TYPE_REAL){
                                    typeerror();
                                }
                                $$.type = TYPE_REAL;
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   COS '(' expr ')'
                            {
                                if ($3.type != TYPE_REAL){
                                    typeerror();
                                }
                                $$.type = TYPE_REAL;
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   LOG '(' expr ')'
                            {
                                // Assumindo logaritmo natural (base e)
                                if ($3.type != TYPE_REAL){
                                    typeerror();
                                }
                                $$.type = TYPE_REAL;
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   ABS '(' expr ')'
                            {
                                if ($3.type == TYPE_REAL){
                                    $$.type = TYPE_REAL;

                                }else if($3.type == TYPE_INT){
                                    $$.type = TYPE_INT;

                                }else{
                                    typeerror();
                                }

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   SQRT '(' expr ')'
                            {
                                if ($3.type != TYPE_REAL){
                                    typeerror();
                                }
                                $$.type = TYPE_REAL;

                                // Se for negativo, gerará erro de execução
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   EXP '(' expr ')'
                            {
                                // Retorna e^x, sendo x o parâmetro
                                if ($3.type != TYPE_REAL){
                                    typeerror();
                                }
                                $$.type = TYPE_REAL;

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   ORD '(' expr ')'
                            {
                                // Retorna o inteiro do parâmetro
                                // É um "casting" de inteiro

                                if ($3.type == TYPE_REAL){
                                    typeerror();
                                }
                                $$.type = TYPE_INT;

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   CHR '(' expr ')'
                            {
                                // Retorna equivalente char do parâmetro
                                // É um "casting" de char

                                if ($3.type == TYPE_REAL){
                                    typeerror();
                                }
                                $$.type = TYPE_CHAR;

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   EOLN '(' expr ')'
                            {
                                // Verifica EOLn do arquivo nomeado pelo parâmetro

                                if ($3.type != TYPE_CHAR){
                                    printf("EOLn: %i", $3.type);
                                    typeerror();
                                }
                                $$.type = TYPE_BOOL;

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        |   EOF_TOKEN '(' expr ')'
                            {
                                // Verifica EOF do arquivo nomeado pelo parâmetro

                                if ($3.type != TYPE_CHAR){
                                    printf("EOF: %i", $3.type);
                                    typeerror();
                                }
                                $$.type = TYPE_BOOL;

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        ;
factor_a                :   MINUS factor
                            { 
                                if ($2.type == TYPE_INT){
                                    $$.type = TYPE_INT;
                                }else if ($2.type == TYPE_REAL){
                                    $$.type = TYPE_REAL;
                                }else
                                    typeerror();
                                
                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }                      
                        |   factor
                            { 
                                $$.type = $1.type; 
                                $$.value = $1.value; 
                            }
                        ;
factor                  :   IDENTIFIER
                            { 
                                // Pesquisa a entrada na tabela de símbolos
                                int res_niv;
                                int res_i;
                                Get_Entry($1, &res_niv, &res_i);

                                if (res_niv == -1){
                                    // Não encontrou na tabela
                                    exit(1);
                                }
                                $$.type = TabelaS[res_i].type;
                                $$.value = TabelaS[res_i].value;
                            }
                        |   constant
                            { 
                                $$.type = $1.type; 
                                $$.value = $1.value; 
                            }
                        |   '(' expr ')'
                            { 
                                $$.type = $2.type; 
                                $$.value = $2.value; 
                            }
                        |   function_ref
                            { 
                                // TODO: tipo função 
                                //       + verificação tipos parâmtros
                                //       + verificaçaõ tipo retorno
                                $$.type = $1.type;
                            }
                        |   NOT factor
                            { 
                                if ($2.type != TYPE_BOOL){
                                    typeerror();
                                }else{
                                    $$.type = TYPE_BOOL;
                                }

                                // TODO: criar quádrupla para calcular valor
                                // $$.value = $1.value; 
                            }
                        ;
constant                :   INT_CONSTANT            
                            { 
                                $$.type = TYPE_INT; 
                                $$.value.integer = $1; 
                                printf("Valor [integer]: %d\n", $1);
                            }
                        |   REAL_CONSTANT
                            { 
                                $$.type = TYPE_REAL; 
                                $$.value.real = $1; 
                                printf("Valor [real]: %f\n", $1);
                            }
                        |   CHAR_CONSTANT
                            { 
                                $$.type = TYPE_CHAR; 
                                $$.value.character = $1; 
                                printf("Valor [character]: %c\n", $1);
                            }
                        |   BOOL_CONSTANT
                            { 
                                $$.type = TYPE_BOOL; 
                                $$.value.boolean = $1; 
                                printf("Valor [boolean]: %i\n", $1);
                            }
                        ;


%%                     

/*
Instala a lista de identificadores 'id_list' (global) de tipo 'type' na 
tabela de símbolos
*/
void installIdentList(char* type){
    //   Obs.: o tamanho do array 'id_list' está na variável global 'q'
    int i = 0;
    // printf("%i declaracoes do tipo %s\n", q, type);

    for (i = 0; i < q; i++){
        // printf("Instalando %s, do tipo %s\n", id_list[i], type);
        union value placeholder;
        int tipo_cst = -1;
        if (strcmp(type, "integer") == 0){
            tipo_cst = TYPE_INT;
        }else if (strcmp(type, "real") == 0){
            tipo_cst = TYPE_REAL;
        }else if (strcmp(type, "boolean") == 0){
            tipo_cst = TYPE_BOOL;
        }else if (strcmp(type, "char") == 0){
            tipo_cst = TYPE_CHAR;
        }
        Instala(id_list[i], tipo_cst, placeholder);

    }
}

/*
Atualiza o atributo 'value' da entrada 'id' da tabela de símbolos
*/
void updateVal(char* id, char* value){
    int res_niv;
    int res_i;
    Get_Entry(id, &res_niv, &res_i);

    // O correto seria:
    // strcpy(TabelaS[res_i].value, value);

    // Ainda não avaliamos expressões para conseguir calcular o value
    // mas podemos testar o updateVal, colocando o contador 'novoVal' na tabela
    char num[200];
    sprintf(num, "%d", novoVal);
    /* strcpy(TabelaS[res_i].value, num); */
    TabelaS[res_i].value.integer = atoi(num);

    novoVal++;
}

int main (void) {
    #if YYDEBUG
        yydebug = 1;     
    #endif 


    /* Inicialização da Tabela de Símbolos */
    /* Primeira posição da tabela é 1. L é o final da árvore */
    L = 1;             
    /* Primeiro nível é 1 */     
    nivel = 1;              
    /* escopo[1] contém o indice do primeiro elemento */
    escopo[nivel] = 0;      

    /* Parsing */
    printf("Parsing...\n");
    if (yyparse() == 0){
        printf("Parse sucessful\n\n");
        printf("Tabela de Simbolos Final:");
        imprimir();     // Imprime a tabela de símbolos ao final
        return 0;
    }else{
        return 1;
    }
	
}

void yyerror (char *s) {
    fprintf (stderr, "%s\n", s);
}

void typeerror(){
    printf("Type-error\n");
    exit(1);
}