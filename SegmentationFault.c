#include <stdio.h>
#include <stdlib.h>

int 
main() {

  char *p = NULL;

  p = (char *) malloc(10);

  *p = 'a';

  free(p);
  return 0;
}
