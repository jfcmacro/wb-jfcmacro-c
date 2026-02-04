#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define SIZE_BUFFER 12

int
main() {
  int fd;
  char buffer[SIZE_BUFFER + 1];
  
  bzero(buffer, SIZE_BUFFER);
  
  fd = syscall(SYS_open, "manualCalling.c", O_RDONLY);

  if (fd == -1) {
    fprintf(stderr, "Error abriendo archivo: %d\n", errno);
    syscall(1, 1);
  }

  int tam;
  tam = syscall(SYS_open, buffer, SIZE_BUFFER);

  if (fd == -1) {
    fprintf(stderr, "Error leyendo archivo: %d\n", errno);
    syscall(SYS_exit, 2);
  }

  buffer[tam] = '\0';
  while (tam != 0) {
    fprintf(stdout, "%s", buffer);
    tam = syscall(SYS_read, fd, buffer, SIZE_BUFFER);

    if (tam == -1) {
      fprintf(stderr, "Error leyendo archivo: %d\n", errno);
      syscall(SYS_exit, 3);
    }
    buffer[tam] = '\0';
  }

  syscall(6, fd); // Cierra el archivo que se esta leyendo.
  syscall(SYS_exit, 0); // Termina 
}
