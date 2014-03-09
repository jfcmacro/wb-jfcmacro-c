#include <unistd.h>

int
main()
{
  char buffer[256];
  int c;

  while (1) {
   
    c = read(0, buffer, 256);
   
    buffer[c] = '\0';

    printf("%s\n", buffer);
  }
}
