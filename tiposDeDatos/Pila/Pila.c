#include <malloc.h>
#include "Pila.h"

int crearPila(pila_pila** pila) {

  if (!pila)
    return EPARINCO;

  *pila = malloc(sizeof(pila_pila));

  if (!*pila)
    return ENOMEMORY;

  (*pila)->cabeza = NULL;
  (*pila)->nElementos = 0;

  return ENOERROR;
}

int
crearElemento(int valor, elemento_pila** elemento) {

  if (!elemento)
    return EPARINCO;

  *elemento = malloc(sizeof(elemento_pila));

  if (!*elemento) 
    return ENOMEMORY;

  (*elemento)->valor = valor;
  (*elemento)->sig = NULL;
  
  return ENOERROR;
}

int
encadenarElemento(elemento_pila* ant, elemento_pila* sig) {
 
  if (!sig)
    return EPARINCO;
  
  sig->sig = ant;
  return NOERROR;
}

int 
push(pila_pila* pila, elemento_pila* elemento) {
  
  if (!pila || !elemento) 
    return EPARINCO;

  encadenarElemento(pila->cabeza, elemento);
  pila->cabeza = elemento;
  pila->nElementos++;
  return NOERROR;
}

int
pushValor(pila_pila* pila, int valor) {

  elemento_pila* elemento;
  int codRet;

  if ((codRet = crearElemento(valor, &elemento)) < 0)
    return codRet;

  return push(pila, elemento);
}

int 
pop(pila_pila* pila, elemento_pila** pelemento) {
  
  if (!pila || !pelemento)
    return EPARINCO;

  if (pila->cabeza == NULL) 
    return EUNDERFLOW;

  *pelemento = pila->cabeza;
  pila->cabeza = pila->cabeza->sig; 
  (*pelemento)->sig = NULL;
  pila->nElementos--;
  
  return ENOERROR;
}

int
popValor(pila_pila* pila, int *pValor) {

  elemento_pila* elemento;
  int codRet;
 
  if ((codRet = pop(pila, &elemento)) < 0)
    return codRet;

  *pValor = elemento->valor;
  borrarElemento(elemento);
  return NOERROR;
}

int
totalElementos(pila_pila *pila) {
  
  if (!pila)
    return EPARINCO;

  return pila->nElementos;
}

int
borrarElemento(elemento_pila* elemento) {
  
  if (!elemento)
    return EPARINCO;

  free(elemento);
  return ENOERROR;
}

int
borrarPila(pila_pila* pila) {

  if (!pila)
    return EPARINCO;

  while(pila->cabeza) {
    elemento_pila* ant = pila->cabeza;
    pila->cabeza = ant->sig;
    free(ant);
  }
  
  free(pila);

  return ENOERROR;
}

