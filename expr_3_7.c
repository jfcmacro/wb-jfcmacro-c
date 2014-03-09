#include <stdio.h>

int
main() {
  int a = 10;
  int b;
  int c;
  int d;
  // a <= 20 ? b = 30: c = 30;
  (a <= 20) ? b : c = 30;
  printf("%d %d %d\n", a, b, c);
  return 0;
}
