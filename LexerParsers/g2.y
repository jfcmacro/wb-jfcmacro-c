/* Grammar g2 */

%{

%}

%token EOF
%token ASSIGN 
%token REF
%token ID

%%

s:  a EOF
  ;

a: i ASSIGN d
 | d
;

i: REF d
 | ID
;

d: i
;

