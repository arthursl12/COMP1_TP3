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
%token ADDOP
%token RELOP
%token MULOP
%token NOT
%token <integer> INT_CONSTANT
%token <real> REAL_CONSTANT
%token <boolean> BOOL_CONSTANT
%token <identifier> IDENTIFIER
%token <character> CHAR_CONSTANT

%start expr_list

%left ADDOP MULOP
%right UMINUS
%nonassoc RELOP
// %type 
// %type <num> line exp term 
// %type <id> assignment

%%

/* descriptions of expected inputs     corresponding actions (in C) */
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
function_ref            :   IDENTIFIER
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