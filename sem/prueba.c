#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <stdlib.h>

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

int
main() {

  int sem;
  union semun semaforo;

  if ((sem = semget(4567, 3, IPC_CREAT | IPC_EXCL | 0666)) < 0) {
    printf("Error: %d\n", errno);
    perror("Error ");
    exit(1);
  }

  semaforo.val = 1;

  if (semctl(sem, 0, SETVAL, semaforo) < 0) {
    printf("Control: %d\n", errno);
    perror("Error semctl 1");
    exit(1);
  }

  semaforo.val = 1;

  if (semctl(sem, 1, SETVAL, semaforo) < 0) {
    printf("Control: %d\n", errno);
    perror("Error semctl 2");
    exit(1);
  }


  semaforo.val = 1;

  if (semctl(sem, 2, SETVAL, semaforo) < 0) {
    printf("Control: %d\n", errno);
    perror("Error semctl 3");
    exit(1);
  }
/*
  if (semctl(sem, 0, IPC_RMID, 0) < 0) {
    printf("Control: %d\n", errno);
    perror("Error semctl 3");
    exit(1);
  }
  */
  exit(0);

      

}

