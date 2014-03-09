#include <stdio.h>

int calcularPosiciones(int nNodos) {
  if(nNodos <= 0) {
    return 0;
  }else{
    return 16 + (nNodos-2)*8 + (nNodos-1)*8 + calcularPosiciones(nNodos-2);
  }
}

int
main(int argc, char *argv[]) {
  
  int i = 0;

  for (; i < 10; i++) {

    fprintf(stdout, "Numero nodos: %d total posiciones: %d\n", 
	    i, calcularPosiciones(i));
  }

}
