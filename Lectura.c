#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define SIZE_BUFFER 1024

int
main() {

  int fd;
  char buffer[SIZE_BUFFER];

  fd = open("/dev/pilot", O_RDONLY);

  if (fd == -1) {
    fprintf(stderr, "Error al abrir el archivo: %d \n", errno);
    exit(1);
  }

  while (read(fd, buffer, SIZE_BUFFER) == SIZE_BUFFER) {
    fprintf(stdout, "%s", buffer);
  }
  fprintf(stdout, "%s", buffer);

  return 0;

}
