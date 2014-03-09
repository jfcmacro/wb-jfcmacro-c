#include <stdio.h>
#include <math.h>

int nDigitos(int n) {

  int nd = 0;

  while (n > 0) {
    nd++;
    n = n / 10;
  }
  return nd;
}

int potencia(int n, int p) {

  int r = 1, i;

  for (i = 0; i < p; i++) {
    r = n * r;
  }

  return r; 
}

void digitosDer(int n) {

  int i, p;

  i = nDigitos(n);
  printf("%d tiene %d digitos\n", n, i);
  
  while (i > 0) {
    int d;
    p = potencia(10, i - 1);
    printf("Potencia: %d\n", p);
    d = (n - (n % p)) / p;
    printf("Digito: %d ", d);
    n = n - d * p;
    i--;
  }
}

int
main() {

  digitosDer(1024);
  return 0;
}
