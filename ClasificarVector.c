#include <stdio.h>

#define MAX 10
#define VERDAD 1
#define FALSO  0

int
main() {
  int vectorA[MAX] = { 15, 31, 23, 15, 75, 23, 41, 15, 31, 85 };
  int vectorB[MAX];
  int m = 0;
  int i, j;

  for (i = 0; i < MAX; i++) {
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
