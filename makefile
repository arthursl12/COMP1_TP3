all: 
	gcc -c lists.c -o lists.o 
	gcc -c codinterm.c -o codinterm.o 
	gcc -c tab.c -o tab.o 
	gcc -c interpr.c -o interpr.o 

	yacc -v -d yysint.y
	gcc -c aux.c -o aux.o
	lex yylex.l
	gcc aux.o tab.o lists.o codinterm.o interpr.o lex.yy.c  y.tab.c -o yysint
	./yysint < testeA.in

clean:
	rm *.o
	rm -rf lex.yy.c y.tab.c y.tab.h yysint *.dSYM *.output

.PHONY: clean

