#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
  char* p;

  p = getenv("tmp");

  if (p != NULL) 
    printf("%s \n", p);
}
