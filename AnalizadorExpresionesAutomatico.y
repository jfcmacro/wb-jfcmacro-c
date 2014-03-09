%{
#include <stdio.h>
%}

%%
command : expr '\n' { printf("El resultado es: %d\n", $1); }
        ;

expr    : expr '+' term { $$ = $1 + $3; }
        | term { $$ = $1; }
        ;

term    : term '*' factor { $$ = $1 * $3; }
        | factor { $$ = $1; }
        ;

factor  : numero { $$ = $1; }
        | '(' expr ')' { $$ = $2; }
        ;

numero  : numero digito { $$ = 10 * $1 + $2; }
        | digit { $$ = $1; }
        ;

digito  : '0' { $$ = 0; }
        | '1' { $$ = 1; }
        | '2' { $$ = 2; }
        | '3' { $$ = 3; }
        | '4' { $$ = 4; }
        | '5' { $$ = 5; }
        | '6' { $$ = 6; }
        | '7' { $$ = 7; }
        | '8' { $$ = 8; }
        | '9' { $$ = 9; }
        ;

%%

int
main(void) {
  yyparse();
  return 0;
}

int
yylex(void) {
  static int done = 0;
  int c;
  if (done) return 0;
  c = getchar();
  if (c == '\n') done = 1;
  return c;
}

int 
yyerror(char *s) {
  printf("%s\n", s);
}
