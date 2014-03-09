#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "GestionRecursos.h"

typedef struct ProccessInfo {
  int pId; 
  int totalRecursos;
  PRecurso *recursos;
} ProcessInfo_t;

void*
pi(void *arg) {

  ProcessInfo_t *info = (ProcessInfo_t *) arg;

  for (;;) {

    int j;

    for (j = 0; j < info->totalRecursos; j++) {

      fprintf(stdout, "Proceso: %d solicita Recurso\n", info->pId);
      solicitarRecurso(info->recursos[j]);
     
    }

    for (j = 0; j < info->totalRecursos; j++) {

      fprintf(stdout, "Proceso: %d liberaRecurso\n", info->pId);
      liberarRecurso(info->recursos[j]);
    }

  }

  return (void *) 0;
}




int
main() {

  PRecurso recursos[6] = { NULL, NULL, NULL, NULL, NULL};
  pthread_t procesos[4];
  int i;

  for (i = 0; i < 6; i++) {
    recursos[i] = crearRecurso();
  }

  ProcessInfo_t *info;

  info = (ProcessInfo_t *) malloc(sizeof(ProcessInfo_t)*4);

  (info+0)->pId = 0;
  (info+0)->totalRecursos = 3;
  (info+0)->recursos = (PRecurso *) malloc(sizeof(PRecurso) * 3);
  (info+0)->recursos[0] = recursos[0];
  (info+0)->recursos[1] = recursos[1];
  (info+0)->recursos[2] = recursos[2];


  (info+1)->pId = 1;
  (info+1)->totalRecursos= 3;
  (info+1)->recursos = (PRecurso *) malloc(sizeof(PRecurso) * 3);
  (info+1)->recursos[0] = recursos[0];
  (info+1)->recursos[1] = recursos[1];
  (info+1)->recursos[2] = recursos[4];

  (info+2)->pId = 2;
  (info+2)->totalRecursos= 3;
  (info+2)->recursos = (PRecurso *) malloc(sizeof(PRecurso) * 3);
  (info+2)->recursos[0] = recursos[1];
  (info+2)->recursos[1] = recursos[2];
  (info+2)->recursos[2] = recursos[4];
  
  (info+3)->pId = 3;
  (info+3)->totalRecursos= 3;
  (info+3)->recursos = (PRecurso *) malloc(sizeof(PRecurso) * 3);
  (info+3)->recursos[0] = recursos[2];
  (info+3)->recursos[1] = recursos[3];
  (info+3)->recursos[2] = recursos[5];


  for (i = 0; i < 4; i++) {

    pthread_create(&procesos[i], NULL, pi, (info + i));
  }

  pthread_join(procesos[0], NULL);
  
}
