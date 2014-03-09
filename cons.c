#include <stdio.h>

int consecutivo() {
  static int n = 0;
  return (n++);
}

int
main() {

  printf("%d\n", consecutivo());
  printf("%d\n", consecutivo());
  printf("%d\n", consecutivo());

  return 0;
  
}
