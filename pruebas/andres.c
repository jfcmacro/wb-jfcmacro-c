#include <stdio.h>
#include <unistd.h>

int
main() {

  int ib, ia;
  float f;

  printf("sizeof(int)=%d sizeof(float)=%d\n", sizeof(int), sizeof(float));

  for (ib = ia = -1; ib != 0; --ib, --ia) {
    f = (float) ib;
    ia = (int) f;
    if (ia != ib) {
      printf("ib = %d ia = %d\n", ib, ia);
    }
    ia = ib;
  }
  exit(0);
}
