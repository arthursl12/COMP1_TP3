all: 
	gcc -c tab.c -o tab.o 
	yacc -v -d yysint.y
	gcc -c aux.c -o aux.o
	lex yylex.l
	gcc aux.o tab.o lex.yy.c  y.tab.c -o yysint 
	# ./yysint < teste1.in
	./yysint < teste2.in

clean:
	rm *.o
	rm -rf lex.yy.c y.tab.c y.tab.h yysint *.dSYM *.output

.PHONY: clean

