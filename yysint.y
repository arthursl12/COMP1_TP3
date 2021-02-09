%{
    #include <stdio.h>    
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "tab.h"

    #define YYDEBUG 0          /* Se ligado, imprime mais informações */

    /* Forward declaration de funções do Lex */
    void yyerror (char *s);
    int yylex();

    /* Globals da Tabela de Símbolos */
    extern int escopo[10];
    extern int nivel;      /* nível atual */
    extern int L;          /* índice do último elemento da tabela */
    extern int Raiz;   

    /* Funções Auxiliares da Tabela de Símbolos */
    void installIdentList(char* type);
    int novoVal = 10;       /* Global para testar o updateVal */
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
}         /* Yacc definitions */



/* Tokens */
%token ADDOP
%token RELOP
%token MULOP
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
%left ADDOP MULOP
%nonassoc RELOP
%nonassoc THEN
%nonassoc ELSE

/* Tipos de alguns símbolos Não-terminais */
%type <string> type decl ident_list

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
assign_stmt             :   IDENTIFIER ASSIGN expr          { updateVal($1,"updt"); }
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
                        |   simple_expr RELOP simple_expr
                        ;
simple_expr             :   term
                        |   simple_expr ADDOP term
                        |   simple_expr '-' term
                        ;
term                    :   factor_a
                        |   term MULOP factor_a
                        ;
function_ref            :   function_ref_par
                        ;
function_ref_par        :   variable '(' expr_list ')'
                        ;
variable                :   simple_variable_or_proc
                        |   function_ref_par
                        ;
simple_variable_or_proc :   IDENTIFIER_F
                        ;
factor_a                :   '-'factor                   
                        |   factor
                        ;
factor                  :   IDENTIFIER
                        |   constant
                        |   '(' expr ')'
                        |   function_ref
                        |   NOT factor
                        ;
constant                :   INT_CONSTANT        
                        |   REAL_CONSTANT
                        |   CHAR_CONSTANT
                        |   BOOL_CONSTANT   
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
        Instala(id_list[i], type, "");
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
    strcpy(TabelaS[res_i].value, num);
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