#include <stdio.h>

struct nodo {
  int valor;
};

typedef struct nodo nodo;
typedef struct nodo *pnodo;
typedef struct nodo **ppnodo;

int
cargarNodo(int n, struct nodo nodo[][10]) {

  int i = 0;
  int j = 0;
    
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
	nodo[i][j].valor = i + j;
      }
    }
}

int
imprimirNodo(int n, struct nodo nodo[][10]) {

  int i = 0;
  int j = 0;
    
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
	printf("matriz[%d][%d]=%d\n", i, j, nodo[i][j].valor);
      }
      
      printf("\n");
    }
}

int
main(int argc, char *argv[]) {

  struct nodo matriz[10][10];
  
  cargarNodo(10, matriz);
  imprimirNodo(10, matriz);

  return 0;

}
