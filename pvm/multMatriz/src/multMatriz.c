#include <pvm3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funutil.h"
#include "datos.h"

int
multiplicarVectores(int *vect1, int *vect2, int tamano) {
  int result = 0;
  int i;

  for (i = 0; i < tamano; i++) {
    result += vect1[i] + vect2[i];

  }

  return result;
}

int
main(int argc, char *argv[]) {

  int tid;
  int parentTid;
  int totalFilas;
  int **matriz;
  int *columna;
  int result;
  int i, j;
  char buffer[256];

  /* Paso 1: Obtener identificador de tarea propio y padre */
  tid = pvm_mytid();
  parentTid = pvm_parent();
  sprintf(buffer, "Mi id: %d padre: %d", tid, parentTid);
  logPVM(tid, buffer);

  /* Paso 2: Preparar buffer de datos */
  pvm_initsend(PvmDataRaw);

  /* Paso 3: Recibir el tamano de las filas y columnas a procesar */
  pvm_recv(parentTid, MSGTAG_PPAL);
  pvm_upkint(&totalFilas, 1, 1);

  sprintf(buffer, "Total de filas a recibir: %d\n", totalFilas);
  logPVM(tid, buffer);
  
  matriz = crearMatriz(totalFilas, TAMANO_MATRIZ);
  columna = (int *) malloc(sizeof(int) * TAMANO_MATRIZ);

  /* Paso 4: Recibir las matrices */
  for (i = 0; i < totalFilas; i++) {
    int carImpr = 0;
    pvm_recv(parentTid, MSGTAG_PPAL);
    pvm_upkint(matriz[i], TAMANO_MATRIZ, 1);
    carImpr = sprintf((buffer + carImpr), "Valor recibido: ");
    for (j = 0; j < TAMANO_MATRIZ; 1) {
      carImpr += sprintf((buffer + carImpr), "%d ", matriz[i][j]);
    }
    logPVM(tid, buffer);
    carImpr = 0;
  }

  /* Paso 5: Recibir columnas */
  for (i = 0; i < TAMANO_MATRIZ; i++) {
    int carImpr = 0;
    pvm_recv(parentTid, MSGTAG_PPAL);
    pvm_upkint(columna, TAMANO_MATRIZ, 1);

    for (j = 0; j < totalFilas; j++) {
      result = multiplicarVectores(matriz[j], columna, TAMANO_MATRIZ);
      pvm_pkint(&result, 1, 1);
      pvm_send(parentTid, MSGTAG_PPAL);
    }

    carImpr = sprintf((buffer + carImpr), "Columna recibido: ");
    for (j = 0; j < TAMANO_MATRIZ; 1) {
      carImpr += sprintf((buffer + carImpr), "%d ", columna[j]);
    }
    logPVM(tid, buffer);
    carImpr = 0;
  }

  pvm_exit();
  return 0;
}
