all:
	lex myscanner.l
	gcc myscanner.c lex.yy.c -o myscanner 
	./myscanner < config.in
	
clean:
	rm myscanner
	rm lex.yy.c