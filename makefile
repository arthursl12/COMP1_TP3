all: aux.o
	lex yylex.l
	gcc aux.o scanner.c lex.yy.c -o yylex 
	./yylex < teste1.in
	./yylex < teste2.in
	./yylex < teste3.in

aux.o:
	gcc -c aux.c -o aux.o 

clean:
	rm *.o
	rm yylex
	rm lex.yy.c

.PHONY: clean