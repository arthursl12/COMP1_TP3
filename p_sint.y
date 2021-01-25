%{
    void yyerror (char *s);
    int yylex();
    #include <stdio.h>     /* C declarations used in actions */
    #include <stdlib.h>
    #include <ctype.h>
    int symbols[52];
    int symbolVal(char symbol);
    void updateSymbolVal(char symbol, int val);

    #define YYDEBUG 1
%}

%union {int integer; float real; int boolean; char character; char* identifier;}         /* Yacc definitions */

%token print
%token exit_command

/* Tokens */
%token ADDOP
%token RELOP
%token MULOP
%token NOT
%token ASSIGN
%token <integer> INT_CONSTANT
%token <real> REAL_CONSTANT
%token <boolean> BOOL_CONSTANT
%token <identifier> IDENTIFIER
%token <character> CHAR_CONSTANT

/* Tokens de Palavras Reservadas */
%token PROGRAM
%token INTEGER REAL BOOLEAN CHAR
%token BEGIN_STMT END
%token IF THEN ELSE
%token DO WHILE
%token UNTIL END
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
%right UMINUS
%nonassoc RELOP
%nonassoc THEN
%nonassoc ELSE
%nonassoc IDX
// %type 
// %type <num> line exp term 
// %type <id> assignment

%%

/* descriptions of expected inputs     corresponding actions (in C) */
    /* Header e Declarações */
program                 :   PROGRAM IDENTIFIER ';' decl_list compound_stmt
decl_list               :   decl_list ';' decl
                        |   decl
                        ;
decl                    :   ident_list ':' type
ident_list              :   ident_list ',' IDENTIFIER
                        |   IDENTIFIER
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
function_ref            :   EOLN
                        |   function_ref_par
                        ;
function_ref_par        :   variable '(' expr_list ')'
                        ;
variable                :   simple_variable_or_proc
                        |   function_ref_par
                        ;
simple_variable_or_proc :   IDENTIFIER
                        ;
factor_a                :   '-'factor %prec UMINUS
                        |   factor
                        ;
factor                  :   IDENTIFIER  %prec IDX
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


%%                     /* C code */

int computeSymbolIndex(char token)
{
	int idx = -1;
	if(islower(token)) {
		idx = token - 'a' + 26;
	} else if(isupper(token)) {
		idx = token - 'A';
	}
	return idx;
} 

/* returns the value of a given symbol */
int symbolVal(char symbol)
{
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}

/* updates the value of a given symbol */
void updateSymbolVal(char symbol, int val)
{
	int bucket = computeSymbolIndex(symbol);
	symbols[bucket] = val;
}

int main (void) {
    #if YYDEBUG
        yydebug = 1;     
    #endif 
	/* init symbol table */
	int i;
	for(i=0; i<52; i++) {
		symbols[i] = 0;
	}

    if (yyparse() == 0){
        printf("Parse sucessful\n");
        return 0;
    }else{
        return 1;
    }
	
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 