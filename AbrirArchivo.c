#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TAM_BUFFER 256
char buffer[TAM_BUFFER];

int
main() {
  int fd;
  ssize_t nBytesLeidos;

  fd = open("/home/fcardona/programas/c/AbrirArchivo.c", O_RDONLY);
  nBytesLeidos = read(fd, buffer, TAM_BUFFER);
  write(1, buffer, nBytesLeidos);
  close(fd);
  _exit(0);
}

