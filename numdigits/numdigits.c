#include <stdio.h>

int
numdigits(int x) {

  int t = x, n = 1;

  while (t >=10) {
    n++;
    t = t / 10;
  }
  return n;
}

int
rnumdigits(int x) {

  if (x < 10) 
    return 1;
  else 
    return 1 + rnumdigits(x / 10);
}

int
main() {

  int x = 1002;

  printf("Numero de digitos: %d RNumero de digitos: %d\n", 
	 numdigits(x), rnumdigits(x));

  return 0;
}


