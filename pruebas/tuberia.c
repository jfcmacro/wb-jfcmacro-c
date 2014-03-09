#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "Encabezado.h"

void
imprimirEncabezado(struct Encabezado *enc) {

  printf("Nombre: %s Numero: %d Datos: %s Valor: %f\n", 
	 enc->nombre, enc->numero, enc->datos, enc->valor);
}

int
main() {

  int tuberia1[2];
  int tuberia2[2];
  int nC;
  char parametro1[10];
  char parametro2[10];
  struct Encabezado *enc;

  enc = (struct Encabezado *) malloc(sizeof(struct Encabezado)); 

  strncpy(enc->nombre, "Mi nombre", TAM_BUFFER);
  enc->numero = 1;
  strncpy(enc->datos, "Datos datos", TAM_BUFFER);
  enc->valor = 20;

  pipe(tuberia1);
  pipe(tuberia2);

  if (fork() == 0) {
    sprintf(parametro1, "%d", tuberia1[0]);
    sprintf(parametro2, "%d", tuberia2[1]);
    close(tuberia1[1]);
    close(tuberia2[0]);
    execl("./hijo", "hijo", parametro1, parametro2, NULL);
    fprintf(stderr, "No puede pasar esto");

  }
  else {
    int status;
    close(tuberia1[0]);
    close(tuberia2[1]);

    write(tuberia1[1], (char *) enc, sizeof(struct Encabezado));
    nC = read(tuberia2[0], enc, sizeof(struct Encabezado));
   
    imprimirEncabezado(enc);

    write(tuberia1[1], (char *) enc, sizeof(struct Encabezado));
    nC = read(tuberia2[0], enc, sizeof(struct Encabezado)); 

    imprimirEncabezado(enc);
    wait(&status);
  }

  exit(0);

}
