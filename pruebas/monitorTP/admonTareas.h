#ifndef ADMONTAREAS_H
#define ADMONTAREAS_H

typedef struct _HiloMonitor HiloMonitor;

int initAdmonTareas(void*, void*, int*,HiloMonitor**);
int estadoTarea(HiloMonitor*);
int semSignalTarea(HiloMonitor *);
int signalPreferenciaTarea(HiloMonitor *);

#endif
