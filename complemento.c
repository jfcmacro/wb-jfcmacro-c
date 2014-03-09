#include <stdio.h>

int
main() {

  unsigned int x = 0xFFFFFFFF;
  unsigned int y = 0x0F0F0F0F;
  printf("%00000000x %00000000x\n", x, (~x + 1));
  printf("%00000000x %00000000x\n", y, (~y + 1));
  return 0;
}
