#include <stdio.h>

int
main(int argc, char *argv[]) {

  int numero1;
  short numero2;
  char numero3;
  int numero4;
  char vector[10];

  fprintf(stdout, "sizeof(numero1): %d sizeof(numero2): %d sizeof(numero3): %d sizeof(numero4): %d\n", 
	  sizeof(numero1), sizeof(numero2), sizeof(numero3), sizeof(numero4));
  fprintf(stdout, "numero1: %p numero2: %p numero3: %p numero4: %p\n", 
	  &numero1, &numero2, &numero3, &numero4);
  fprintf(stdout, "vector: %p\n", vector);
  return 0;
}
		
