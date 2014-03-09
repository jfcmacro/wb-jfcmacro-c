#include "admonTareas.h"

#ifndef COLATAREAS_H
#define COLATAREAS_H
typedef struct _ColaTareas ColaTareas;
int initColaTareas(ColaTareas **);
void insertarTarea(ColaTareas **, int, HiloMonitor *);
void borrarTarea(ColaTareas **, int);
int colaVacia(ColaTareas *);
void borrarCola(ColaTareas **);
HiloMonitor *desencolarTarea(ColaTareas **tarea);
#endif
