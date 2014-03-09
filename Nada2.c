#include <stdio.h>

int
main() {
  int x = -100;

  if (x) {
    printf("Es un valor de \"true\": %d\n", x);
  }
  else {
    printf("Es un valor de \"falso\": %d\n", x);
  }
  return 0;
}
