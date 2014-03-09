#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int
main() {
  
  int fd1;
  int fd2;
  char buffer[2048];
  int leido;

  fd1 = open("/dev/gps", 0);

  if (fd1 < 0) {
    perror("Error abriendo archivo");
    exit(1);
  }

  fd2 = open("archivo.txt", 0);

  if (fd2 < 0) {
     perror("Error abriendo archivo");
     exit(1);
  }

  leido = read(fd2, buffer, 2048);

  fprintf(stdout, "Lo leido: %d\n", leido);

  write(fd1, buffer, leido);
  
  close(fd1);
  close(fd2);
  exit(0);
}
