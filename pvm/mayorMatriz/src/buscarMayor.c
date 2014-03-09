#include <pvm3.h>
#include <stdlib.h>
#include <stdio.h>
#include "funutil.h"
#include "datos.h"

int
buscarMayor(int *vector, int tamano) {
  int i;
  int mayor = vector[0];

  for (i = 1; i < tamano; i++) {
    if (mayor < vector[i]) {
      mayor = vector[i];
    }
  }
  return mayor;
}

int
main(int argc, char *argv[]) {

  int tid;
  int parentTid;
  int bufid;
  int filasColumnas[2];
  int **matriz;
  int i,j;
  int mayorActual;
  char buffer[256];

  /* Paso 1: Obtener identificador de tarea propio y padre */
  tid = pvm_mytid();
  parentTid = pvm_parent();
  sprintf(buffer, "Mi id: %d padre: %d", tid, parentTid);
  Log(buffer);

  /* Paso 2: Preparar buffer de datos */
  bufid = pvm_initsend(PvmDataRaw);

  /* Paso 3: Recibir el tamano de las filas y columnas a procesar */
  pvm_recv(parentTid, MSGTAG_PPAL);
  pvm_upkint(filasColumnas, 2, 1);
  
  matriz = crearMatriz(filasColumnas[0], filasColumnas[1]);
  
  /* Paso 4: Recibir los datos y procesar */
  mayorActual = 0;
  for (i = 0; i < filasColumnas[0]; i++) {
    int mayor;
    pvm_recv(parentTid, MSGTAG_PPAL);
    pvm_upkint(matriz[i], filasColumnas[1], 1); 
    mayor = buscarMayor(matriz[i], filasColumnas[1]);
    if (mayor > mayorActual) {
      mayorActual = mayor;
    }
  }

  /* Paso 5: Enviar respuesta */

  pvm_pkint(&mayorActual, 1, 1);
  pvm_send(parentTid, MSGTAG_PPAL);

  pvm_exit();
  return 0;
}
