#include <stdio.h>
#include <stdlib.h>
#include <pvm3.h>

#define TIEMPO_A_DORMIR_DFL  30

int 
main(int argc, char *argv[]) {

  int tid;
  int tiempoADormir = TIEMPO_A_DORMIR_DFL;

  tid = pvm_mytid();

  if (tid < 0) {
    fprintf(stderr, "Error conectandome a PVM\n");
    exit(1);
  }

  printf("%d\n", tid);

  if (argc > 1) {
    tiempoADormir = strtol(argv[1], NULL, 10);
  }

  sleep(tiempoADormir);

  pvm_exit();
  fprintf(stdout, "El proceso terminara\n");
  exit(0);
}
