#include "admonTareas.h"
#include "admonHilos.h"

#ifndef ADMONMONITOR_H
#define ADMONMONITOR_H

typedef struct _AdmonMonitor AdmonMonitor;

int initAdmonMonitor(int, int,AdmonMonitor **);
int contadorActivos(AdmonMonitor*);
int contadorInactivos(AdmonMonitor *);
int contadorTotal(AdmonMonitor *);
int transaccion(AdmonMonitor *, void*, void*, int, HiloMonitor**);
int terminar(AdmonMonitor *, HiloMonitor *);
int modificar(AdmonMonitor *,int,int);
int destructor(AdmonMonitor *);
int encolarTarea(AdmonMonitor *,int,HiloMonitor *);
int cambiarTipoHilo(AdmonHilos *);
int signalPreferencia(AdmonMonitor *);
int semSignalCola(AdmonMonitor *);
#endif
