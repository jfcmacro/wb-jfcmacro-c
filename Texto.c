#include <stdio.h>

int
main() {

  int i;

  for (i = 0; i < 64000; i++) {
    fprintf(stdout, "%d", i);
  }
  return 0;
}
