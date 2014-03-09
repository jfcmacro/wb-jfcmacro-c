#include <stdio.h>

unsigned int
invert(unsigned int x, unsigned int p, unsigned int n) {

  unsigned int mascara = (~(~0<<n)<<p);

  return (~(mascara & x) & mascara) | (~mascara & x);
}

int
main() {
  unsigned int x = 0xFF11ABFF;

  printf("%X %X\n", x, invert(x, 8, 8));
  return 0;
}
