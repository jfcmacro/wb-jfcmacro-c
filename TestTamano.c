#include <stdio.h>

int
main() {

  fprintf(stdout, "Int: %d\n", sizeof(int));
  fprintf(stdout, "Unsigned Int: %d\n", sizeof(unsigned int));
  fprintf(stdout, "short Int: %d\n", sizeof(short));
  fprintf(stdout, "long int: %d\n", sizeof(long));
  return 0;
}
