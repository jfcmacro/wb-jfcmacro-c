#include <stdio.h>
#include <stdlib.h>

int
main(void) {
  int *q;
  int *p = (int*) malloc(sizeof(int));
  *p = 4;
  printf("%d - %p\n", *p, p);
  free(p);
  q = (int*) malloc(sizeof(int));
  q++;
  printf("%d - %p\n", *p, p);
  printf("%d - %p\n", *q, q);
  return 0;
  
}
