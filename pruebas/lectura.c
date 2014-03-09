#include <stdio.h>
#include <unistd.h>

int
main()
{
  char buffer[256];
  int i;
  int c;

  i = 0;
  while ((c = getchar()) != EOF) {
    buffer[i++] = c;
  }    
  buffer[i] = '\0';

  printf("buffer: %s %d\n", buffer, strlen(buffer));
}


