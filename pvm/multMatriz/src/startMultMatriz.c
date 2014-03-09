#include <stdio.h>
#include <pvm3.h>
#include "funutil.h"
#include "datos.h"

int
main() {
  int i,j;
  int n = TAMANO_MATRIZ;
  int m = TAMANO_MATRIZ;
  int o = TAMANO_MATRIZ;
  int **matriz1;
  int **matriz2;
  int **matrizResult;
  int tid;
  int taskTid[N_TASK];
  int tmp;
  int *columna;

  /* Paso 1: conectarse a pvmd */
  tid = pvm_mytid();
  fprintf(stdout, "Identificador obtenido: %d\n", tid);

  matriz1 = crearMatrizLimitada(n,m, 10, 0);
  matriz2 = crearMatrizLimitada(m,o, 10, 0);
  matrizResult = crearMatrizLimitada(n,o, 0, 0);

  fprintf(stdout, " Matriz 1\n");
  imprimirMatriz(stdout, matriz1, TAMANO_MATRIZ);

  fprintf(stdout, " Matriz 2\n");
  imprimirMatriz(stdout, matriz2, TAMANO_MATRIZ);

  /* Paso 2: crear subtareas de procesamiento */
  fprintf(stdout, "Paso 2\n");
  if (pvm_spawn("multMatriz", NULL, 0, NULL, N_TASK, taskTid) < N_TASK) {
    pvm_perror("No se pudo crear los nodos");
    exit(0);
  }

  /* Paso 3: prepara los datos de los procesos */
  fprintf(stdout, "Paso 3\n");
 
  pvm_initsend(PvmDataRaw);
  
  /* Numero de filas de cada proceso */
  tmp = n / N_TASK;
  pvm_pkint(&tmp, 1, 1);
  pvm_mcast(taskTid, N_TASK, MSGTAG_PPAL);
  
  fprintf(stdout, "Enviar matrices a los procesos\n");
  /* Se entrega las filas a cada proceso */
  
  for (i = 0; i < n; i += N_TASK) {
    for (j = 0; j < N_TASK; j++) {
      pvm_pkint(matriz1[i+j], m, 1);
      pvm_send(taskTid[j], MSGTAG_PPAL);
    } 
  }

  /* Paso 4: difunde las columnas */
  fprintf(stdout, "Paso 4\n");
  columna = (int *) malloc(sizeof(int) * m);
  for (i = 0; i < o; i++) { 
    /* Copia la columna */
    for (j = 0; j < m; j++) {
      columna[j] = matriz2[j][i];
    }
    pvm_pkint(columna, m, 1);
    pvm_mcast(taskTid, N_TASK, MSGTAG_PPAL);
  }

  /* Paso 5: Espera los resultados y arma la matriz de resultados */
  fprintf(stdout, "Paso 5\n");
  for (i = 0; i < o; i += N_TASK) {
    for (j = 0; j < N_TASK; j++) {
      int k;
      for (k = 0; k < TAMANO_MATRIZ; k++) {
	pvm_recv(taskTid[j], MSGTAG_PPAL);
	pvm_upkint(&matrizResult[k][i + j], 1, 1);
	fprintf(stdout, "Recibido parametro i: %d j: %d\n", k, j + i);
      }
    }
  }

  fprintf(stdout, " Resultado \n");
  imprimirMatriz(stdout, matrizResult, TAMANO_MATRIZ);

  pvm_exit();
  return 0;
}
