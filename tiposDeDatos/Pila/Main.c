#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

void
codigoError(const char* mensaje, int codRet, int valRet);

int
main(int argc, char *argv[]) {

  pila_pila *pila;
  elemento_pila *elemento;
  int codRet;

  codigoError("No pudo crear la pila", crearPila(&pila), 1);

  codigoError("No pudo crear elemento 10", crearElemento(10, &elemento), 1);

  codigoError("No pudo insertar elemento en la pila", push(pila, elemento), 1);
  
  codigoError("No pudo crear elemento 20", crearElemento(20, &elemento), 1);

  codigoError("No pudo insertar elemento en la pila", push(pila, elemento), 1);
  
  while ((codRet = pop(pila, &elemento)) == NOERROR) {
    printf("Elemento: %d\n", elemento->valor);
  }

  switch (codRet) {
  case NOERROR:
  case EUNDERFLOW:
    break;
  default:
    codigoError("No pudo sacar un elemento de la pila", codRet, 1);
    break;
  }

  exit(0);
}

void
codigoError(const char* mensaje, int codRet, int valRet) {

  if (codRet < 0) {
    fprintf(stderr, "%s: %d\n", mensaje, codRet);
    exit(valRet);
  }
  return;
}
