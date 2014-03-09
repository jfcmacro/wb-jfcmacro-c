#include <stdio.h>

#define N 3
#define M 3
#define VERDAD 1
#define FALSO  0

int matriz[N][M] = { { 1, 4, 7}, {4, 2, 9}, {7, 3, 3} };

int
main(int argc, const char* argv[]){

  int i;
  int j;
  int esSimetrica = VERDAD;

  for (i = 0; i < N && esSimetrica; i++) {
    for (j = 0; j < M && esSimetrica; j++) {
      if (matriz[i][j] != matriz[i][j]) {
	esSimetrica = FALSO;
      }
    }
  }
  if (esSimetrica) {
    printf("Es simetrica\n");
  }
  else {
    printf("No es simetrica\n");
  }
  return 0;
}
