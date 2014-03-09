#include <stdio.h>

int
main() {

  int i = 1;
  int *pI;
  float *pF;
  void *pV;

  pI = &i;
  pV = pI;
  pF = (float *) pV;

  printf("%d\n", i);
  printf("%f\n", *pF);
  
  i = i + 1;

  printf("%d\n", i);
  printf("%f\n", *pF);

  return 0;
}
