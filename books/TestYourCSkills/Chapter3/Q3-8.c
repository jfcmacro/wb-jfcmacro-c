#include <stdio.h>
 


int
main() {
  int a, b;
  a = 2;
  printf("%d \n", a <= 20 ? (b = 10) : (b = 30));
  a = 21;
  printf("%d \n", a <= 20 ? (b = 10) : (b = 30));
  return 0;
}
