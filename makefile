all: aux.o
	yacc -d p_sint.y
	lex p_lex.l
	gcc aux.o scanner.c lex.yy.c  y.tab.c -o p_lex 
	./p_lex < config.in

aux.o:
	gcc -c aux.c -o aux.o 

clean:
	rm *.o
	rm p_lex
	rm -rf lex.yy.c y.tab.c y.tab.h p_lex p_lex.dSYM p_sint.dSYM

.PHONY: clean

