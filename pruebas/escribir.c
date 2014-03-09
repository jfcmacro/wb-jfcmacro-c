#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define ARCHIVO "escribir.dat"

int
main() {

  int fd;
  int i;

  unlink(ARCHIVO);

  if ((fd = open(ARCHIVO, O_CREAT | O_EXCL | O_RDWR , 0664)) < 0) {
    fprintf(stderr, "Error al abrir %s %d\n", ARCHIVO, errno);
    exit(1);
  }

  for (i = 0; i < 100; i++) {
    if (write(fd, &i, sizeof(int)) < 0) {
      fprintf(stderr, "Error al escribir %s %d\n", ARCHIVO, errno);
      exit(1);
    }
  }

  return 0;
}
