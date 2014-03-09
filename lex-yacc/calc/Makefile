
all: calc

y.tab.c : calc.yacc
	yacc -d calc.yacc

lex.yy.c : calc.lex
	lex calc.lex

calc : y.tab.c lex.yy.c
	cc -o calc y.tab.c lex.yy.c
