#include <stdio.h>

int
main() {

  int a[] = { 1, 2, 4, 5};
  int i = 0;

  for (i = 0; i < sizeof(a)/sizeof(int); i++) {
    printf("a[i] = %d i[a] = %d\n", a[i], i[a]);
    printf("*(a + i) = %d *(i + a) = %d\n", *(a + i), *(i + a));
  }
  return 0;
}
