#include <stdio.h>

#define MAX    1000
#define VERDAD 1
#define FALSO  0

int
main() {
  int vectorA[MAX];
  int vectorB[MAX];
  int n = 0;
  int value;
  int i, j, m;
  do {
    fscanf(stdin, "%d", &value);
    if (value != -1) {
      vectorA[n++] = value;
    }
  } while (value != -1 && n < MAX);

  m = 0;
  for (i = 0; i < n; i++) {
    int esta = FALSO;
    for (j = 0; j < m && !esta; j++) {
      if (vectorB[j] == vectorA[i]) {
	esta = VERDAD;
      }
    }
    
    if (!esta) {
      vectorB[m++] = vectorA[i];
    }
  }
  for (i = 0; i < m; i++) {
    printf("vector[%d]=%d\n", i, vectorB[i]);
  }
  printf("\ncon m=%d\n", m);
  return 0;
}
