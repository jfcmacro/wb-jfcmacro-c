/* calc.l */

/* calculator #1 */
%{
#include "y.tab.h"
#include <stdlib.h>
#include <string.h>
void yyerror(char *);
%}

%%

[a-z]   {
/* return a duplicate of yytext */
yylval.sValue =
return VARIABLE;
}

[0-9]+  {
yylval.iValue = atoi(yytext);
return INTEGER;
}

[-+()=/*\n] { return *yytext; }

[ \t]  ;   /* skip whitespace */

.   yyerror("Unknown character");

%%

int yywrap(void) {
return 1;
}


