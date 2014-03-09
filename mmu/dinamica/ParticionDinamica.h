#ifndef PARTICIONDINAMICA_H

#define SIN_PROCESO (unsigned int) -1

enum estadoMemoria { Libre, Ocupada };
typedef unsigned int Pid_t;

struct ParticionMemoria {
  unsigned int posicionInicial;   /* Posicion inicial */
  unsigned int posicionFinal;     /* Posicion final */
  enum estadoMemoria estado;         /* Libre o Ocupada */
  Pid_t pid;                      /* Proceso dueno o SIN_PROCESO */
};

struct ElementoLista {
  struct ParticionMemoria *pElemento;
  struct ElementoLista    *sigElemento;
};

struct ParticionMemoria*
crearParticion();

struct ElementoLista*
crearElementoLista();

void
encadenarElementoLista(struct ElementoLista *ant, struct ElementoLista *nuevo);

struct ElementoLista*
siguienteElementoLista(struct ElementoLista *actual);

void
establecerElementoEnLista(struct ElementoLista *actual,
			  struct ParticionMemoria *nuevo);

struct ParticionMemoria*
obtenerParticionElementoLista(struct ElementoLista *actual);

unsigned long
tamanoParticion(struct ParticionMemoria *particion);

void
borrarParticion(struct ParticionMemoria *particion);

struct ParticionMemoria*
mejorAjuste(struct ElementoLista* cabezaLista, 
	    unsigned long tamano,
	    Pid_t proceso);

struct ElementoLista*
liberarMemoriaCompactandola(struct ElementoLista cabezaLista, Pid_t proceso);

#endif
