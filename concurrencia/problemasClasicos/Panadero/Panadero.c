#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define TRUE   1
#define FALSE  0

#define N      3

int numero[N];
int escogiendo[N];
int nCrit = 0;

int
maximo(int *numero, int n)
{
  int i;
  int max;

  max = *numero;
  for (i = 0; i < n; i++) 
    if (max < *(numero + i))
      max = *(numero + i); 

  return max;
}

void* hilo(void *arg) {
  static int valRet;
  int i;
  int j;

  i =  (int) arg;
  fprintf(stdout, "Pointer argumento: %ld Argumento: %d\n", (int) arg , i);

  for (;;) {
    
    escogiendo[i] = TRUE;
    numero[i] = maximo(numero, N) + 1;
    // fprintf(stdout, "numero[%d]=%d\n", i, numero[i]);
    escogiendo[i] = FALSE;
    
    for (j = 0; j < N; j++) {
      while (escogiendo[j]) 
	;
      while ((numero[j] != 0) &&
	     ((numero[j] < numero[i]) || 
	      ((numero[j] == numero[i]) && ( i < j))))
	;
    }
    
    /* Entro a la seccion critica */

    nCrit++;
    if (nCrit > 1) {
      fprintf(stderr, "Violacion del requerimiento #1 %d\n", nCrit);
      {
	int k = 0;
	
	for (k = 0; k < N; k++)
	  printf("Numero[%d]= %d, Escogiendo[%d] = %d\n",
		 k, numero[k], k, escogiendo[k]);
      }
      exit(1);
    }
    nCrit--;

    /* Salio de la seccion critica */
    numero[i] = 0;
  }
  return (void *) &valRet;
}


int main(int argc, char *argv[])
{
  
  pthread_t tid; /*tipo identificador de hilo*/
  void* valorRet;
  int i;

  for (i = 0; i < N; i++) {
    fprintf(stdout, "Antes Argumento: %d\n", i);

    pthread_create(&tid, NULL, hilo, (void *) i);
  }
	
  pthread_join(tid, &valorRet); /*espara por la terminacion del hilo*/

  return 0;
}
