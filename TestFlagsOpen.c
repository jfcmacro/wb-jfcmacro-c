#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int
main() {
  int fd;
  fd = open("/tmp/Nuevo",  O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
  fprintf(stdout, "fd: %d\n", fd);
  close(fd);
  fd = open("/tmp/Nuevo",  O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
  fprintf(stdout, "fd: %d\n", fd);
  close(fd);

  return 0;
}
