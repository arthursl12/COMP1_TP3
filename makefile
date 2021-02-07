all: 
	gcc -c tab.c -o tab.o 
	yacc -d -v yysint.y
	gcc -c aux.c -o aux.o
	lex yylex.l
	gcc aux.o tab.o lex.yy.c  y.tab.c -o yysint 
	# ./p_lex < config0.in
	# ./p_lex < config1.in
	# ./p_lex < config2.in
	# ./p_lex < config3.in
	# ./p_lex < config4.in
	# ./p_lex < config5.in
	# ./p_lex < config6.in
	# ./p_lex < teste1.in
	# ./yysint < teste1.in
	./yysint < teste2.in

clean:
	rm *.o
	rm -rf lex.yy.c y.tab.c y.tab.h yysint *.dSYM

.PHONY: clean

