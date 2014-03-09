%{
#define COMMAND        0
#define LABEL          1
#define IDENTIFICADOR  2

#define COMMAND_ADD    0
#define COMMAND_ADDF   1
%}

delim          [ \t\n]
eb             {delim}+
letra          [A-Za-z]
digito         [0-9]
id             {letra}({letra}|{digito})*
numero         {digito}+
%%

{eb}                   { /* no hay accion */ } 
[a|A][d|D][d|D]        { yylval = COMMAND_ADD;  return(COMMAND); }
[a|A][d|D][d|D][f|F]   { yylval = COMMAND_ADDF; return(COMMAND); }
{id}                   { yylval = instalar_id(); return(IDENTIFICADOR);}
{id}:                  { yylval = instalar_label(); return(LABEL); }
%%
