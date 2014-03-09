#include <stdio.h>

int
main() {

  unsigned char x = 0;
  int i = 0;

  for (i = 0; i < 216255; i++) {
    x++;
  }
  printf("%d\n", x);
}
