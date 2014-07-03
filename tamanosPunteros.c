#include <stdio.h>

struct Prueba {
  int v1;
  long int v2;
  int v3;
};

int
main(int argc, char *argv[]) {

  struct Prueba *p;

  printf("%d\n", sizeof(*p));
  printf("%d\n", sizeof(struct Prueba));
}
