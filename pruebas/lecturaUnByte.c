#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int
main() {
  
  int fd;
  char buffer;

  fd = open("/dev/gps", 0);

  if (fd < 0) {
    perror("Error abriendo archivo");
    exit(1);
  }

  while (read(fd, &buffer, 1) == 1) {
    write(1, &buffer, 1);
  }
  
  exit(0);
}
