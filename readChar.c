#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
  int c;
  int e;
  int o;
  int last;
  
  while ((c = getchar()) != EOF) {
    switch (c) {
    case ' ':
      e++; break;
    case '_':
      o++; break;
    default:
      last = c; break;
    }
  }

  printf("e: %d o: %d last: %c\n", e, o, last);

  return EXIT_SUCCESS;
}
