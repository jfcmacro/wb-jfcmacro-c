%{
#include <math.h>

#define YYSTYPE double
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%left UNARYMINUS UNARYPLUS
%%
list: /* nada */
	| list '\n'
	| list expr '\n' { printf("\t%.8g\n", $2); }
;	
expr:	NUMBER	{ $$ = $1; }
	| '-' expr %prec UNARYMINUS { $$ = -$2; }
	| '+' expr %prec UNARYPLUS  { $$ = $2; }
	| expr '%' expr { $$ = doubleMod($1, $3); }
	| expr '+' expr { $$ = $1 + $3; }
	| expr '-' expr { $$ = $1 - $3; }
	| expr '*' expr { $$ = $1 * $3; }
	| expr '/' expr { $$ = $1 / $3; }
	| '(' expr ')'  { $$ = $2; }
	;
%%
#include <stdio.h>
#include <ctype.h>
char *progname;
int  lineno = 1;

double
doubleMod(double dividendo, double divisor) {

	int partInt1;
	int partInt2;
	double normal1;
	double normal2;

	normal1 = frexp(dividendo, &partInt1);
	normal2 = frexp(divisor, &partInt2);

	fprintf(stdout, "Dividendo: %lf normal: %lf parte entera: %d\n",
		dividendo, normal1, partInt1);
	fprintf(stdout, "Divisor: %lf normal: %lf parte entera: %d\n",
		divisor, normal2, partInt2);

	return 0.0;
}

int
main(int argc, char *argv[]) {

	progname = argv[0];
	yyparse();
}

int
yylex() {

	int c;

	while ((c=getchar()) == ' ' || c == '\t')
		;

	if (c == EOF) 
		return 0;

	if (c == '.' || isdigit(c)) { /* numero */
		ungetc(c, stdin);
		scanf("%lf", &yylval);
		return NUMBER;
	}
	
	if (c == '\n')
		lineno++;
	return c;
}

int
yyerror(char *s) {

	warning(s, (char *) 0);
}

warning(char *s, char *t) {

	fprintf(stderr, "%s: %s", progname, s);

	if (t) 
		fprintf(stderr, " %s", t);
	fprintf(stderr, " near line %d\n", lineno);
}
