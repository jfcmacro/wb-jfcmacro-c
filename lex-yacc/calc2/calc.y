//calc.y

%{
  #include <stdio.h>
  void yyerror(char *);
  int yylex(void);

  
  %}

%union {
  int   iValue; /* integer value */
  char* sValue;/* a string value */
};


%token <iValue> INTEGER 
%token <sValue> VARIABLE
%left '+' '-'
%left '*' '/'

%type <iValue> expression

%%

program:
program statement '\n'
| /* NULL */
;

statement:
expression  { printf("%d\n", $1); }
| VARIABLE '=' expression   { sym[$1] = $3; }
;

expression:
INTEGER
| VARIABLE  { $$ = sym[$1]; }
| expression '+' expression { $$ = $1 + $3; }
| expression '-' expression { $$ = $1 - $3; }
| expression '*' expression { $$ = $1 * $3; }
| expression '/' expression { $$ = $1 / $3; }
| '(' expression ')'{ $$ = $2; }
;

%%

void yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
}

int main(void) {
  void print_header();
  print_header(); // do not remove
  yyparse();
}


