#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int
main() {

  printf(" flags: %d mode: %d\n", O_WRONLY, 0);
  printf(" flags: %d mode: %d\n", O_RDONLY, 0);
  printf(" flags: %d mode: %d\n", O_WRONLY | O_CREAT | O_APPEND,
	 S_IWUSR | S_IRUSR);
  return 0;
}
