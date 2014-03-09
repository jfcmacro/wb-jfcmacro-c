#include <stdio.h>
#include <stdlib.h>

void
f(char *argv[]) {
  while (*argv) {
    fprintf(stdout, "Argumento: %s\n", *argv);
    argv++;
  }
}

int
main(int argc, char **argv) {
  char **argv2;

  argv2 = (char **) malloc(sizeof(char *) * 3);

  f(argv);
  argv2[0] = "Hola";
  argv2[1] = "Mundo";
  argv2[2] = NULL;
  f(argv2);
  return 0;
}
