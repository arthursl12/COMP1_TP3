all: aux.o
	yacc -d -v p_sint.y
	gcc -c aux.c -o aux.o 
	lex p_lex.l
	gcc aux.o scanner.c lex.yy.c  y.tab.c -o p_lex 
	# ./p_lex < config0.in
	# ./p_lex < config1.in
	# ./p_lex < config2.in
	# ./p_lex < config3.in
	# ./p_lex < config4.in
	# ./p_lex < config5.in
	./p_lex < config6.in






aux.o:
	gcc -c aux.c -o aux.o 

clean:
	rm *.o
	rm p_lex
	rm -rf lex.yy.c y.tab.c y.tab.h p_lex p_lex.dSYM p_sint.dSYM

.PHONY: clean

