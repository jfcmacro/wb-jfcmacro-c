#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int token; /* Mantiene el carácter actual de entrada para el análisis
	      sintáctico */

/* declaraciones para permitir la recursión deliberada */
void command(void);
int expr(void);
int term(void);
int factor(void);
int number(void);
int digit(void);

void
error(void) {
  printf("Error sintactico\n");
  exit(1);
}

void
getToken(void) {
  token = getchar();
}

void
match(char c) {
  if (token == c) getToken();
  else error();
}

void
command(void) {
  /* command -> expr '\n' */
  int result = expr();

  if (token == '\n') 
    printf("El resultado es: %d\n", result);
  else error();
}

int
expr(void) {
  /* expr -> term { '+' term } */
  int result = term();

  while (token == '+') {
    match('+');
    result += term();
  }
  return result;
}

int
term(void) {
  /* termino -> factor { '*' factor } */
  int result = factor();

  while (token == '*') {
    match('*');
    result *= factor();
  }
  return result;
}

int
factor(void) {
  /* factor -> '(' expr ')' | número */

  int result;
  if (token == '(') {
    match('(');
    result = expr();
    match(')');
  }
  else
    result = number();

  return result;
}

int
number(void) {
  /* number -> digit { digit } */
  int result = digit();
  while (isdigit(token)) {
    result = 10 * result + digit();
  }
  return result;
}

int
digit(void) {
  /* digit -> '0' | '1' | '2' | '3' | '4'
           | '5' | '6' | '7' | '8' | '9' */
  int result;

  if (isdigit(token)) {
    /* el valor numérico de un carácter dígito
       es la diferencia entre su valor ascii
       y el valor ascii del carácter '0'
    */
    result = token - '0';
    match(token);
  }
  else {
    error();
  }
  return result;
}

void 
parse(void) {
  getToken();
  command();
}

int
main(void) {
  parse();
  return 0;
}

