#include <stdio.h>

int
main() {
  int a = 1;
  char *c = (char *) &a;
  
  printf("%p\n", &a);
  if (c[0] == 1) {
    printf("little endian");
  }
  else {
    printf("big endian");
  }
  return 0;
}
