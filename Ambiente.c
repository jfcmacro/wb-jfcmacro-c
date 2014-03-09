#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main() {
  char *p;
  p = getenv("PEPITO");
  if (p) {
    printf("%s\n", p);
  }
  sleep(60);
  p = getenv("PEPITO");
  if (p) {
    printf("%s\n", p);
  }
  return 0;
}
