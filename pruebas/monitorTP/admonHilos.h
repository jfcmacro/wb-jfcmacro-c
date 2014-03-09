#ifndef ADMONHILOS_H
#define ADMONHILOS_H

typedef struct _HiloMonitor HiloMonitor;
typedef struct _MonitorTP MonitorTP;
typedef struct _AdmonHilos AdmonHilos;

int initAdmonHilos (int,AdmonHilos**,MonitorTP*);
int initAdmonHilosRemanentes (int, AdmonHilos**,MonitorTP*);
int obtenerEstadoHilo(AdmonHilos*);
int asignarTareaHilo(HiloMonitor *,AdmonHilos *);
int cambiarNecesario(AdmonHilos *);
int signalPreferenciaHilos(AdmonHilos *);
#endif
