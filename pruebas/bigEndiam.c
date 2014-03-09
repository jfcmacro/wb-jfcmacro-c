#include <stdio.h>

int
main(int argc, char *argv[]) {
  unsigned int numero = 0x03020100;
  unsigned char *p;
  int i;

  p = (char *) &numero;

  fprintf(stdout, "Main: %p\n", main);
  fprintf(stdout, "argv[0]: %p\n", argv[0]);

  for (i = 0; i < sizeof(numero); i++) {
    fprintf(stdout, "%p %c\n", p + i, *(p + i) + '0');
  }
  fflush(stdout);
  return 0;
}
		
