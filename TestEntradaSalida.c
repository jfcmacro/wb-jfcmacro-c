#include <stdio.h>

int
main() {

  int n;

  fscanf(stdin, "%d", &n);

  fprintf(stdout, "%d\n", n + 1);

  fprintf(stderr, "Hay un problema!\n");

  return 0;
}
