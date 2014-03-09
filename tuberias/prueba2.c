#include <unistd.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[]) {

  char mensaje[] = "                                      ";

  for (;;) {
    int length = sizeof(mensaje);

    read(0, mensaje, length);
    
    write(1, mensaje, length);
  }
}
