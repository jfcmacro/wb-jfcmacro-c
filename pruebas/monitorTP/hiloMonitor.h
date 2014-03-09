#include "admonTareas.h"

#ifndef HILOMONITOR_H
#define HILOMONITOR_H
char *obtenerEstado(HiloMonitor *);
int estaActivo(HiloMonitor *);
int estaInactivo(HiloMonitor *);
int haTerminado(HiloMonitor *);
#endif
