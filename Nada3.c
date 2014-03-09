#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

int
main() {
  int fd, fd2;
  char nombre[] = "Nada.c";
  char *p;
  ssize_t tam;

  p = (char *) malloc(512);

  fd = open(nombre, O_RDONLY);

  if (fd == -1) {
    fprintf(stderr, "Error: no se pudo abrir el archivo\n");
    exit(1);
  }

  fprintf(stdout, "direccion puntero: %p\n", p);
  tam = read(fd, p, 512);
  // *(p + tam) = '\0';
  fprintf(stdout, "%s\n", p);

  fprintf(stdout, "fd: %d\n", fd);
  free(p);
  close(fd);
  fd2 = open("Nada2.c", O_RDONLY);
  fprintf(stdout, "fd: %d\n", fd2);

  return 0;
}
