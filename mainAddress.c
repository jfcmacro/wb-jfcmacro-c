#include <stdio.h>

char buffer[2000];

int
main(void) {
  int i;
  for (i = 0; i < 2000; i++) {
    buffer[i] = (char) i % 128 + 32;
  }
  printf("main: %p buffer: %p s \n", main, buffer);
  return 0;
}
