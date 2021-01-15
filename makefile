all: aux.o
	lex p_lex.l
	gcc aux.o scanner.c lex.yy.c -o p_lex 
	./p_lex < config.in

aux.o:
	gcc -c aux.c -o aux.o 

clean:
	rm *.o
	rm p_lex
	rm lex.yy.c

.PHONY: clean