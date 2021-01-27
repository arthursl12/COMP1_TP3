all: aux.o
	lex p_lex.l
	gcc aux.o scanner.c lex.yy.c -o p_lex 
	./p_lex < teste1.in
	./p_lex < teste2.in
	./p_lex < teste3.in

aux.o:
	gcc -c aux.c -o aux.o 

clean:
	rm *.o
	rm p_lex
	rm lex.yy.c

.PHONY: clean