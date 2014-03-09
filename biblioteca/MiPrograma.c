#include <stdio.h>
#include "biblioteca.h"

int
main() {

  fprintf(stdout, "llamando a: %d\n", a(2));
  fprintf(stdout, "llamando b: %d\n", b());
  fprintf(stdout, "llamando c: %d\n", c(2,4));
  return 0;
}
