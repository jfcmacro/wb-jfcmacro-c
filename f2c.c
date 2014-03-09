#include <stdio.h>

float
f2c(float fahr) {
  return (5.0 / 9.0) * (fahr - 32.0); 
}
int
main() {
  float fahr = 70.5;
  printf("fahr: %5.5f cel: %5.5f \n", fahr, f2c(fahr));
  return 0;
}
