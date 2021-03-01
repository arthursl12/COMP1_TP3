%{
    #include <stdio.h>    
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include <ctype.h>
    #include "tab.h"
    #include "lists.h"
    #include "codinterm.h"

    #include "aux.h"


    #define YYDEBUG 1          /* Se ligado, imprime mais informações */


    /* Forward declaration de funções do parser */
    void yyerror (char *s);
    void typeerror();
    int yylex();
    void tempTipo(int* tipo1, int* tipo2, intmdt_addr_t* s1, intmdt_addr_t* s3);
    bool isNumber(int tipo);

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

    /* Lista de Quádruplas geradas */
    intmdt_code_t *intermediate_code;
%}


%code requires{
    #include "codinterm.h"
}

%union {
    int integer; 
    float real; 
    int boolean; 
    char character; 
    char* string; 
    char* lexeme_str; 
    intmdt_addr_t* intmdt_addr;


    /* Tipos de Não-terminais */
    struct expr { 
        int type; 
        union value value;
    } expr;

    struct node_expr_lst {
        struct expr expr;
        struct node* next;
    } node;
    struct expr_lst { 
        struct node* first;
        int qtd_terms;
    } expr_lst;

}         /* Yacc definitions */

/* Tokens */
/* Tokens operações */
%token <lexeme_str> RELOP
%token <lexeme_str> MULOP
%token <lexeme_str> ADDOP
%token MINUS            // -
// Obs.: o analisador sintático decide se é a subtração ou o menos unário

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
%left ADDOP MINUS MULOP
%nonassoc RELOP
%nonassoc THEN
%nonassoc ELSE

/* Tipos de alguns símbolos Não-terminais */
%type <string> type decl ident_list
%type <intmdt_addr> constant factor factor_a expr simple_expr term
%type <intmdt_addr> function_ref
%type <expr_lst> expr_list

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

        int tipo1 = TabelaS[res_i].type;
        int tipo2 = $3->type;

        // Se for temporário, procure na Tabela de Símbolos seu tipo de verdade
        if (tipo1 == TS_ENTRY ){
            int idx = TabelaS[res_i].value.TS_idx;
            tipo1 = TabelaS[idx].type;
        }
        if (tipo2 == TS_ENTRY){
            int idx = $3->value.TS_idx;
            tipo2 = TabelaS[idx].type;
        }

        // Verificação de Tipos
        if (tipo1 == TYPE_REAL && tipo2 == TYPE_INT){
            // Pode colocar int em real, nada a ser feito
        }else if (tipo1 != tipo2){
            printf("IDType: %i\n", TabelaS[res_i].type);
            printf("ExprType: %i\n", $3->type);
            typeerror();
            YYABORT;
        }

        // Geração da Quádrupla
        printf("IDENTIFIER := expr\n");
       	intmdt_addr_t *dest = malloc (sizeof(intmdt_code_t));
        if (dest == NULL) {
            yyerror("Error: malloc in ASSIGN");
            YYABORT;
        }
        dest->type = TS_ENTRY;
        dest->value.TS_idx = res_i;
        gen(intermediate_code, ":=", $3, NULL, dest);
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
        $$->type = $1->type; 
        $$->value = $1->value; 
    }
                        |   simple_expr RELOP simple_expr
    {
        // Verificação de Tipos
        if (strcmp($2,"==") == 0 || strcmp($2,"!=") == 0){
            // Não importa os tipos dos operandos
            $$->type = TYPE_BOOL; 
            
            // TODO: criar quádrupla para calcular valor
            // $$->value = $1->value; 
        }else if (strcmp($2,"<") == 0 || strcmp($2,"<=") == 0 
               || strcmp($2,">") == 0 || strcmp($2,">=") == 0){
            if ($1->type != TYPE_INT && $1->type != TYPE_REAL){
                typeerror();
                YYABORT;
            }else if ($3->type != TYPE_INT && $3->type != TYPE_REAL){
                typeerror();
                YYABORT;
            }
            $$->type = TYPE_BOOL; 

            // TODO: criar quádrupla para calcular valor
            // $$->value = $1->value; 
        }else{
            printf("Lexema RELOP não encontrado\n");
            exit(1);
        }
    }
                        ;
simple_expr             :   term
    { 
        $$ = $1;
    }
                        |   simple_expr ADDOP term
    {
        if (strcmp($2,"+") == 0){
            // Se algum for temporário, procure na tabela seu tipo de verdade
            int tipo1 = $1->type;
            int tipo2 = $3->type;
            tempTipo(&tipo1, &tipo2, $1, $3);
            
            // Verificação de Tipos + Geração da Quádrupla
            if (isNumber(tipo1) && isNumber(tipo2)){
                if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                    // Dois inteiros
                    printf("simple_expr -> simple_expr + term (int,int)\n");
       	     		intmdt_addr_t *temp = newtemp(TYPE_INT);
                    gen(intermediate_code, "+", $1, $3, temp);
                    $$ = temp;
                }else{
                    // Pelo menos um real
                    printf("simple_expr -> simple_expr + term (real)\n");
       	     		intmdt_addr_t *temp = newtemp(TYPE_REAL);
                    gen(intermediate_code, "+", $1, $3, temp);
                    $$ = temp;
                }
            }else{
                typeerror();
                YYABORT;
            }
        }else if (strcmp($2,"or") == 0){
            // Se algum for temporário, procure na tabela seu tipo de verdade
            int tipo1 = $1->type;
            int tipo2 = $3->type;
            tempTipo(&tipo1, &tipo2, $1, $3);
            
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_BOOL && tipo2 == TYPE_BOOL){
                printf("simple_expr -> simple_expr or term\n");
                intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                printf("TODO: truelist e falselist\n");
                gen(intermediate_code, "or", $1, $3, temp);
                $$ = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else{
            printf("Lexema ADDOP não encontrado: %s\n", $2);
            yyerror("");
            YYABORT;
        }
    }
                        |   simple_expr MINUS term
    {
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = $1->type;
        int tipo2 = $3->type;
        tempTipo(&tipo1, &tipo2, $1, $3);
        
        // Verificação de Tipos + Geração da Quádrupla
        if (isNumber(tipo1) && isNumber(tipo2)){
            if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                // Dois inteiros
                printf("simple_expr -> simple_expr - term (int,int)\n");
                intmdt_addr_t *temp = newtemp(TYPE_INT);
                gen(intermediate_code, "-", $1, $3, temp);
                $$ = temp;
            }else{
                // Pelo menos um real
                printf("simple_expr -> simple_expr - term (real)\n");
                intmdt_addr_t *temp = newtemp(TYPE_REAL);
                gen(intermediate_code, "-", $1, $3, temp);
                $$ = temp;
            }
        }else{
            typeerror();
            YYABORT;
        }
    }
                        ;
term                    :   factor_a
    { 
        printf("term -> factor_a\n");
        $$ = $1; 
    } 
                        |   term MULOP factor_a
    {
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = $1->type;
        int tipo2 = $3->type;
        tempTipo(&tipo1, &tipo2, $1, $3);
            
        if (strcmp($2,"*") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (isNumber(tipo1) && isNumber(tipo2)){
                if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                    // Dois inteiros
                    printf("term -> term * factor_a (int,int)\n");
                    intmdt_addr_t *temp = newtemp(TYPE_INT);
                    gen(intermediate_code, "*", $1, $3, temp);
                    $$ = temp;
                }else{
                    // Pelo menos um real
                    printf("term -> term * factor_a (real)\n");
                    intmdt_addr_t *temp = newtemp(TYPE_REAL);
                    gen(intermediate_code, "*", $1, $3, temp);
                    $$ = temp;
                }
            }else{
                typeerror();
                YYABORT;
            }
        }else if(strcmp($2,"/") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (isNumber(tipo1) && isNumber(tipo2)){
                printf("term -> term / factor_a (real)\n");
                intmdt_addr_t *temp = newtemp(TYPE_REAL);
                gen(intermediate_code, "*", $1, $3, temp);
                $$ = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else if (strcmp($2,"div") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                printf("term -> term div factor_a (int,int)\n");
                intmdt_addr_t *temp = newtemp(TYPE_INT);
                gen(intermediate_code, "div", $1, $3, temp);
                $$ = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else if (strcmp($2,"mod") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_INT && tipo2 == TYPE_INT){
                printf("term -> term mod factor_a (int,int)\n");
                intmdt_addr_t *temp = newtemp(TYPE_INT);
                gen(intermediate_code, "mod", $1, $3, temp);
                $$ = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else if (strcmp($2,"and") == 0){
            // Verificação de Tipos + Geração da Quádrupla
            if (tipo1 == TYPE_BOOL && tipo2 == TYPE_BOOL){
                printf("term -> term and factor_a\n");
                intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                printf("TODO: truelist e falselist\n");
                gen(intermediate_code, "and", $1, $3, temp);
                $$ = temp;
            }else{
                typeerror();
                YYABORT;
            }
        }else{
            printf("Lexema MULOP não encontrado: %s\n", $2);
            yyerror("");
            YYABORT;
        }
    }
                        ;
function_ref            :   SIN '(' expr ')'
                            {
                                int tipo1 = $3->type;
                                if (tipo1 == TS_ENTRY){
                                    int idx = $3->value.TS_idx;
                                    tipo1 = TabelaS[idx].type;
                                }
                                
                                if (tipo1 != TYPE_REAL){
                                    typeerror();
                                    YYABORT;
                                }
                                $$->type = TYPE_REAL;
                                // TODO: criar quádrupla para calcular valor
                                // $$->value = $1->value; 
                            }
                        |   COS '(' expr ')'
                            {
                                if ($3->type != TYPE_REAL){
                                    typeerror();
                                    YYABORT;
                                }
                                $$->type = TYPE_REAL;
                                // TODO: criar quádrupla para calcular valor
                                // $$->value = $1->value; 
                            }
                        |   LOG '(' expr ')'
                            {
                                // Assumindo logaritmo natural (base e)
                                if ($3->type != TYPE_REAL){
                                    typeerror();
                                    YYABORT;
                                }
                                $$->type = TYPE_REAL;
                                // TODO: criar quádrupla para calcular valor
                                // $$->value = $1->value; 
                            }
                        |   ABS '(' expr ')'
                            {
                                if ($3->type == TYPE_REAL){
                                    $$->type = TYPE_REAL;

                                }else if($3->type == TYPE_INT){
                                    $$->type = TYPE_INT;

                                }else{
                                    typeerror();
                                    YYABORT;
                                }

                                // TODO: criar quádrupla para calcular valor
                                // $$->value = $1->value; 
                            }
                        |   SQRT '(' expr ')'
                            {
                                if ($3->type != TYPE_REAL){
                                    typeerror();
                                    YYABORT;
                                }
                                $$->type = TYPE_REAL;

                                // Se for negativo, gerará erro de execução
                                // TODO: criar quádrupla para calcular valor
                                // $$->value = $1->value; 
                            }
                        |   EXP '(' expr ')'
                            {
                                // Retorna e^x, sendo x o parâmetro
                                if ($3->type != TYPE_REAL){
                                    typeerror();
                                    YYABORT;
                                }
                                $$->type = TYPE_REAL;

                                // TODO: criar quádrupla para calcular valor
                                // $$->value = $1->value; 
                            }
                        |   ORD '(' expr ')'
                            {
                                // Retorna o inteiro do parâmetro
                                // É um "casting" de inteiro

                                if ($3->type == TYPE_REAL){
                                    typeerror();
                                    YYABORT;
                                }
                                $$->type = TYPE_INT;

                                // TODO: criar quádrupla para calcular valor
                                // $$->value = $1->value; 
                            }
                        |   CHR '(' expr ')'
                            {
                                // Retorna equivalente char do parâmetro
                                // É um "casting" de char

                                if ($3->type == TYPE_REAL){
                                    typeerror();
                                    YYABORT;
                                }
                                $$->type = TYPE_CHAR;

                                // TODO: criar quádrupla para calcular valor
                                // $$->value = $1->value; 
                            }
                        |   EOLN '(' expr ')'
                            {
                                // Verifica EOLn do arquivo nomeado pelo parâmetro

                                if ($3->type != TYPE_CHAR){
                                    printf("EOLn: %i", $3->type);
                                    typeerror();
                                    YYABORT;
                                }
                                $$->type = TYPE_BOOL;

                                // TODO: criar quádrupla para calcular valor
                                // $$->value = $1->value; 
                            }
                        |   EOF_TOKEN '(' expr ')'
                            {
                                // Verifica EOF do arquivo nomeado pelo parâmetro

                                if ($3->type != TYPE_CHAR){
                                    printf("EOF: %i", $3->type);
                                    typeerror();
                                    YYABORT;
                                }
                                $$->type = TYPE_BOOL;

                                // TODO: criar quádrupla para calcular valor
                                // $$->value = $1->value; 
                            }
                        ;
factor_a                :   MINUS factor
    { 
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = $2->type;
        if (tipo1 == TS_ENTRY){
            int idx = $2->value.TS_idx;
            tipo1 = TabelaS[idx].type;
        }
        
        // Verificação de Tipos
        printf("factor_a -> - factor \n");
        intmdt_addr_t *temp;
        if (tipo1 == TYPE_INT){
            temp = newtemp(TYPE_INT);
        }else if (tipo1 == TYPE_REAL){
            temp = newtemp(TYPE_INT);
        }else{
            typeerror();
            YYABORT;
        }

        // Geração da Quádrupla
        gen(intermediate_code, "1-", $2, NULL, temp);
        $$ = temp;
    }                      
                        |   factor
    { 
        printf("factor_a -> factor\n");
        $$ = $1;
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

                                TabelaS[res_i].class = CLS_VARIABLE;
                                $$->type = TS_ENTRY;
                                $$->value.TS_idx = res_i;
                            }
                        |   constant
                            { 
                                $$ = $1; 
                            }
                        |   '(' expr ')'
                            { 
                                $$ = $2; 
                            }
                        |   function_ref
                            { 
                                // TODO: tipo função 
                                //       + verificação tipos parâmtros
                                //       + verificaçaõ tipo retorno
                                $$ = $1;
                            }
                        |   NOT factor
    { 
        // Se algum for temporário, procure na tabela seu tipo de verdade
        int tipo1 = $2->type;
        if (tipo1 == TS_ENTRY){
            int idx = $2->value.TS_idx;
            tipo1 = TabelaS[idx].type;
        }
        
        // Verificação de Tipos                         
        if (tipo1 != TYPE_BOOL){
            typeerror();
            YYABORT;
        }

        // Geração da Quádrupla
        printf("factor -> NOT factor\n");
        intmdt_addr_t *temp = newtemp(TYPE_BOOL);
        printf("TODO: truelist e falselist\n");
        gen(intermediate_code, "NOT", $2, NULL, temp);
        $$ = temp;
    }
                        ;
constant                :   INT_CONSTANT            
                            {
                                intmdt_addr_t *temp = newtemp(TYPE_INT);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.integer = $1;
                                $$ = temp;
                                
                                intmdt_addr_print($$);
                                printf("\n");
                            }
                        |   REAL_CONSTANT
                            { 
                                intmdt_addr_t *temp = newtemp(TYPE_REAL);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.real = $1;
                                $$ = temp;
                                
                                intmdt_addr_print($$);
                                printf("\n");
                            }
                        |   CHAR_CONSTANT
                            { 
                                intmdt_addr_t *temp = newtemp(TYPE_CHAR);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.character = $1;
                                $$ = temp;

                                intmdt_addr_print($$);
                                printf("\n");
                            }
                        |   BOOL_CONSTANT
                            { 
                                intmdt_addr_t *temp = newtemp(TYPE_BOOL);
                                TabelaS[temp->value.TS_idx].class = CLS_CST;
                                TabelaS[temp->value.TS_idx].value.boolean = $1;
                                $$ = temp;
                                
                                intmdt_addr_print($$);
                                printf("\n");
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
        int cls = -1;
        if (strcmp(type, "integer") == 0){
            tipo_cst = TYPE_INT;
            cls = CLS_VARIABLE;
        }else if (strcmp(type, "real") == 0){
            tipo_cst = TYPE_REAL;
            cls = CLS_VARIABLE;
        }else if (strcmp(type, "boolean") == 0){
            cls = CLS_VARIABLE;
            tipo_cst = TYPE_BOOL;
        }else if (strcmp(type, "char") == 0){
            cls = CLS_VARIABLE;
            tipo_cst = TYPE_CHAR;
        }
        Instala(id_list[i], tipo_cst, cls, placeholder);
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
    // strcpy(TabelaS[res_i]->value, value);

    // Ainda não avaliamos expressões para conseguir calcular o value
    // mas podemos testar o updateVal, colocando o contador 'novoVal' na tabela
    char num[200];
    sprintf(num, "%d", novoVal);
    /* strcpy(TabelaS[res_i]->value, num); */
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

    /* Inicialização da lista de quádruplas */
    intermediate_code = init_code();

    /* Parsing */
    printf("Parsing...\n");
    if (yyparse() == 0){
        printf("Parse sucessful\n\n");
        /* printf("Tabela de Simbolos Final:"); */
        /* imprimir();     // Imprime a tabela de símbolos ao final */
        print_intmdt_code(intermediate_code);
        free_intmdt_code(intermediate_code);
        return 0;
    }else{
        free_intmdt_code(intermediate_code);
        return 1;
    }
}

/* 
Se algum tipo for temporário (apontar para a tabela de símbolos) busca na 
tabela de símbolos o tipo verdadeiro
*/
void tempTipo(int* tipo1, int* tipo2, intmdt_addr_t* s1, intmdt_addr_t* s3){
    if (*tipo1 == TS_ENTRY){
        int idx = s1->value.TS_idx;
        *tipo1 = TabelaS[idx].type;
    }
    if (*tipo2 == TS_ENTRY){
        int idx = s3->value.TS_idx;
        *tipo2 = TabelaS[idx].type;
    }
}

/* Verifica se o tipo passado é um número (inteiro ou real) */
bool isNumber(int tipo){
    return (tipo == TYPE_INT || tipo == TYPE_REAL);
}

void yyerror (char *s) {
    fprintf(stderr, "%s\n", s);
    fprintf(stderr,"At line %d\n",yylineno);
}

void typeerror(){
    yyerror("Type-error!");
}