all:
	lex p_lex.l
	gcc scanner.c lex.yy.c -o p_lex 
	./p_lex < config.in
	
clean:
	rm p_lex
	rm lex.yy.c