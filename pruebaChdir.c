#include <stdio.h>
#include <unistd.h>

int
main() {

  int r;

  r = chdir("/home/fcardona");
  
  if (r) {
    printf("Error: %d\n",r);
  }
  else {
    printf("Cambio: %d\n", r);
  }
}
