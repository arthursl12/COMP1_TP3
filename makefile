all:
	lex echo.l
	gcc lex.yy.c -o myscanner 
	./myscanner < config.in
	
clean:
	rm myscanner
	rm lex.yy.c