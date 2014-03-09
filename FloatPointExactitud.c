#include <stdio.h>
#include <float.h>

float
div(float dividendo, float divisor) {
  return (dividendo / divisor);
}

int
main() {

  float n = 1.0f / 3.0f;
  double np = 1.0 / 3.0;
  float zero = 0.0f;
  float numero = 1.0f;

  printf("%10.10f %10.20g\n", n, np);
  printf("Dividendo: %10.10f Divisor: %10.10f Resultado: %10.10f\n", 
	 zero, numero, div(zero,numero));
  printf("Dividendo: %10.10f Divisor: %10.10f Resultado: %10.10f\n", 
	 numero, zero, div(numero,zero));

  return 0;
}
