#include <stdio.h>

unsigned int
nSegmento(unsigned int dir) {
  return (dir & 0x00F00000) >> 20;
}

unsigned int
offset(unsigned int dir) {
  return dir & 0x000FFFFF;
}

int
main(void) {
  unsigned int dir = 0x00A12345;

  printf("%x %x \n", nSegmento(dir), offset(dir));
  return 0;
}

