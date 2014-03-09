#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include "GestionRecursos.h"

#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
/* la union semun se define al incluir <sys/sem.h> */
#else
/* según X/OPEN tenemos que definirla nosostros mismos */
union semun {
  int val;                    /* valor para SETVAL */
  struct semid_ds *buf;       /* buffer para IPC_STAT, IPC_SET */
  unsigned short int *array;  /* array para GETALL, SETALL */
  struct seminfo *__buf;      /* buffer para IPC_INFO */
};
#endif

static int key_sem = 0x0f0f0000;

static void
incrementarClave() {
  key_sem++;
}

/* struct Recurso { */
/*   int semid; */
/*   int semkey; */
/* }; */


PRecurso
crearRecurso() {
  
  mode_t um;
  union semun control;
  int flags;
  mode_t mode;

  PRecurso pRecurso = (PRecurso) malloc(sizeof(Recurso));

  if (pRecurso == (PRecurso)0)
    return pRecurso;

  um = umask(077);
  umask(um);
  mode = 0666 & ~um;

  flags = IPC_CREAT | IPC_EXCL;

  pRecurso->semid = semget(key_sem, 1, mode | flags);
  incrementarClave();
  pRecurso->semkey = key_sem;

  if (pRecurso->semid < 0) {
    free(pRecurso);
    return (PRecurso) NULL;
  }

  control.val = 1;
  if (semctl(pRecurso->semid, 0, SETVAL, control) < 0) {
    semctl(pRecurso->semid, 0, IPC_RMID, control);
    free(pRecurso);
    return (PRecurso) NULL;
  }

  return pRecurso;
}

void
solicitarRecurso(PRecurso recurso) {
  struct sembuf semBuff;

  semBuff.sem_num = 0;
  semBuff.sem_op = -1;
  semBuff.sem_flg = 0;

  if (semop(recurso->semid, &semBuff, 1) < 0) {
    fprintf(stderr, "Error: en el recurso\n");
  }
}

void 
liberarRecurso(PRecurso recurso) {

  struct sembuf semBuff;

  semBuff.sem_num = 0;
  semBuff.sem_op = 1;
  semBuff.sem_flg = 0;

  if (semop(recurso->semid, &semBuff, 1) < 0) {
    fprintf(stderr, "Error: en el recurso\n");
  }
}

void
destruirRecurso(PRecurso recurso) {

  union semun un;

  semctl(recurso->semid, 1, IPC_RMID, un);

  free(recurso);
}
