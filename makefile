all:
	yacc -d calc.y
	lex calc.l
	gcc -g lex.yy.c y.tab.c -o calc
	./calc

clean:
	rm -rf lex.yy.c y.tab.c y.tab.h calc calc.dSYM