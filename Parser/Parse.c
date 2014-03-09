#include <ctype.h>
#include <stdio.h>

typedef enum {PLUS, TIMES, LPAREN, RPAREN,
	      EOL, NUMBER, ERROR} TokenType;

int numval;
int curr_char;

TokenType getToken(void) {

  while ((curr_char = getchar()) == ' ');
  if (isdigit(curr_char)) {
    numval = 0;
    while (isdigit(curr_char)) {
      numval = 10 * numval + curr_char - '0';
      curr_char = getchar();
    }
    
    ungetc(curr_char, stdin);
    return NUMBER;
  }
  else {
    switch(curr_char) {
    case '(': return LPAREN; break;
    case ')': return RPAREN; break;
    case '+': return PLUS; break;
    case '*': return TIMES; break;
    case '\n': return EOL; break;
    default: return ERROR; break;
    }
  }
}

int
main() {

  TokenType token;

  do {
    token = getToken();
    switch(token) {
    case PLUS: printf("PLUS\n"); break;
    case TIMES: printf("TIMES\n"); break;
    case LPAREN: printf("LPAREN\n"); break;
    case RPAREN: printf("RPAREN\n"); break;
    case EOL: printf("EOL\n"); break;
    case NUMBER: printf("NUMBER: %d\n", numval); break;
    case ERROR: printf("ERROR: %c\n", curr_char); break;
    }
  } while (token != EOL);
  return 0;
}
