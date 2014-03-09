#include "ParticionDinamica.h"
#include <stdio.h>

struct ParticionMemoria*
mejorAjuste(struct ElementoLista* cabezaLista, 
	    unsigned long tamano, 
	    Pid_t proceso) {
  
  struct ElementoLista *actual;
  struct ParticionMemoria *pMemoriaActual = NULL;
  struct ElementoLista *posibleNuevaParticion = NULL;
  unsigned long menorDif = 0;
  unsigned short primera = 1;
  
  if (cabezaLista == NULL) {
    return NULL;
  }

  actual = cabezaLista;
  
  do {

    pMemoriaActual = obtenerParticionElementoLista(actual);

    if (pMemoriaActual->estado == Libre) {
      
      if (tamanoParticion(pMemoriaActual) > tamano) {

	if (primera) {
	  menorDif = tamanoParticion(pMemoriaActual) - tamano;
	  posibleNuevaParticion = actual;
	  primera = 0;
	}
	else if (menorDif > (tamanoParticion(pMemoriaActual) - tamano)) {
	  menorDif = tamanoParticion(pMemoriaActual) - tamano;
	  posibleNuevaParticion = actual;
	}
      }
    }
    
    actual = siguienteElementoLista(actual);
  } while (actual != NULL);

  pMemoriaActual = NULL;

  if (posibleNuevaParticion != NULL) {
    struct ElementoLista* nuevoElemento = crearElementoLista();
    struct ParticionMemoria *pNueva = crearParticion();

    pMemoriaActual = obtenerParticionElementoLista(actual);
    pNueva->posicionInicial = pMemoriaActual->posicionInicial + tamano;
    pNueva->posicionFinal   = pMemoriaActual->posicionFinal;
    pNueva->estado = Libre;
    pNueva->pid = SIN_PROCESO;

    nuevoElemento->pElemento = pNueva;
    
    pMemoriaActual->posicionFinal = pMemoriaActual->posicionInicial 
      + tamano - 1;
    pMemoriaActual->estado = Ocupada;
    pMemoriaActual->pid = proceso;
  }
  
  return pMemoriaActual;
}
