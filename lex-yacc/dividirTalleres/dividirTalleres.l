/* escaner para un dividir programas */

%{
#include <stdio.h>

char filename[256];
int tallerNro = 1;
FILE *of;
%}

%option noyywrap

%%

\\f    { fclose(of);
         sprintf(filename, "Taller1_%d.txt", tallerNro);
         tallerNro++;
         of = fopen(filename, "w+");
       }
\\n    {  }
.      { 
         fputc(yytext[0], of);
       }

%% 
int
main(int argc, char *argv[]) {
   if (argc == 2) {
      sprintf(filename, "Taller1_%d.txt", tallerNro);
      tallerNro++;
      of = fopen(filename, "w+");
      yyin = fopen(argv[1], "r");
   }
   else {
      yyin = stdin;
   }
   yylex();
} 