#include <stdio.h>

int
main() {

  int i;

  for (i = 0; i < 64000; i++) {
    write(1, &i, sizeof(int));
  }
  return 0;
}
