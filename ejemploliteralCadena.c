#include <stdio.h>


char t[5] = { 'H', 'e', 'l', 'l', 'o' };
char s[6] = { ' ', 'w', 'o', 'r', 'l', 'd' };

int
main(void) {
  char p[] = "Hello";
  char *q = "Hello";
  *p = 'h';
  // *q = 'h';
  printf("%s\n", p);
  printf("%s\n", q);
  printf("%s\n", t);
  return 0;
}
