#include <stdio.h>
#include <pvm3.h>
#include "funutil.h"
#include "datos.h"

int
main() {
  int i;
  int j;
  int n = TAMANO_MATRIZ;
  int m = TAMANO_MATRIZ;
  int **matriz;
  int tid;
  int taskTid[N_TASK];
  int filasColumnas[2];
  int bufid; 
  int actualMayor;
  int mayorRecibido;

  /* Paso 1: conectarse a pvmd */
  tid = pvm_mytid();
  fprintf(stdout, "Identificador obtenido: %d\n", tid);

  matriz = crearMatriz(n,m);

  /* Paso 2: crear subtareas de procesamiento */
  fprintf(stdout, "Paso 2\n");
  if (pvm_spawn("buscarMayor", NULL, 0, NULL, N_TASK, taskTid) < N_TASK) {
    pvm_perror("No se pudo crear los nodos");
    exit(0);
  }

  /* Paso 3: prepara los datos de los procesos */
  fprintf(stdout, "Paso 3\n");
  filasColumnas[0] = TAMANO_MATRIZ / N_TASK;
  filasColumnas[1] = TAMANO_MATRIZ;
  
  bufid = pvm_initsend(PvmDataRaw);
  
  pvm_pkint(filasColumnas, 2, 1);
  pvm_mcast(taskTid, N_TASK, MSGTAG_PPAL);
  
  pvm_mkbuf(PvmDataRaw);

  for (i = 0; i < TAMANO_MATRIZ; i += N_TASK) {
    for (j = 0; j < N_TASK; j++) {
      pvm_mkbuf(PvmDataRaw);
      pvm_pkint(matriz[i + j], TAMANO_MATRIZ, 1);
      pvm_send(taskTid[j], MSGTAG_PPAL);
    }
  }

  /* Paso 4: espera los resultados */
  fprintf(stdout, "Paso 4\n");
  actualMayor = 0;
  for (i = 0; i < N_TASK; i++) {
    pvm_recv(taskTid[i], MSGTAG_PPAL);
    pvm_upkint(&mayorRecibido, 1, 1);
    if (mayorRecibido > actualMayor) {
      actualMayor = mayorRecibido;
    }
  }

  printf("El mayor es:%d\n", actualMayor);

  pvm_exit();
  return 0;
}
