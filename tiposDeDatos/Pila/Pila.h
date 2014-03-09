/* Pila.h */
#ifndef _PILA_H
#define _PILA_H pila_h

#define ENOERROR    0
#define NOERROR     ENOERROR
#define EUNDERFLOW -1
#define ENOMEMORY  -2
#define EOVERFLOW  -3
#define EPARINCO   -4

struct Elemento_PILA_H {
  int valor;
  struct Elemento_PILA_H *sig;
};

struct Pila_PILA_H {
  struct Elemento_PILA_H *cabeza;
  int nElementos;
};

typedef struct Pila_PILA_H  pila_pila;
typedef struct Elemento_PILA_H elemento_pila;

int crearPila(pila_pila**);
int crearElemento(int valor, elemento_pila**);
int encadenarElemento(elemento_pila* ant, elemento_pila* sig);
int push(pila_pila*, elemento_pila *);
int pushValor(pila_pila*, int valor);
int pop(pila_pila*, elemento_pila**);
int popValor(pila_pila*, int *pvalor);
int totalElementos(pila_pila*);
int borrarPila(pila_pila*);
int borrarElemento(elemento_pila*);

#endif



 
