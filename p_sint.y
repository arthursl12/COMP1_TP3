%{
    void yyerror (char *s);
    int yylex();
    #include <stdio.h>     /* C declarations used in actions */
    #include <stdlib.h>
    #include <ctype.h>
    int symbols[52];
    int symbolVal(char symbol);
    void updateSymbolVal(char symbol, int val);
%}

%union {int integer; float real; int boolean; char character; char* identifier;}         /* Yacc definitions */

%token print
%token exit_command
%token ADDOP
%token RELOP
%token MULOP
%token <integer> INT_CONSTANT
%token <real> REAL_CONSTANT
%token <boolean> BOOL_CONSTANT
%token <identifier> IDENTIFIER
%token <character> CHAR_CONSTANT


%start term
// %type 
// %type <num> line exp term 
// %type <id> assignment

%%

/* descriptions of expected inputs     corresponding actions (in C) */

term   	: INT_CONSTANT          
		| IDENTIFIER			
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
	/* init symbol table */
	int i;
	for(i=0; i<52; i++) {
		symbols[i] = 0;
	}

	return yyparse ( );
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 