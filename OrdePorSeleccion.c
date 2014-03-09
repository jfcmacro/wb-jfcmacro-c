#include <stdio.h> 

int vector[] = { 20, 22, 12, 13 ,15 };

int
main(int argc, const char *argv[]) {
  int i;
  int j;
  printf("%d\n", sizeof(vector) / sizeof(int));

  for (i = 0; i < sizeof(vector) / sizeof(int); i++) {
    int posMenor = i;
    for (j = i; j < (sizeof(vector) / sizeof(int)) - 1; j++) {
      if (vector[i] > vector[j]) {
	posMenor = j;
      }
    }
    // Intercambiar
    if (i != j) {
      int valor = vector[i];
      vector[i] = vector[j];
      vector[j] = valor;
    }
    printf("vector[%d]=%d\n", i, vector[i]);
  }

  return 0;
}
