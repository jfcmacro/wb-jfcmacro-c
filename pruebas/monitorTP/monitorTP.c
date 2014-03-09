#include "monitorTP.h"
#include "admonMonitor.h"
#include "memoria.h"
#include "errores.h"
#include "admonTareas.h"
#include <stdio.h>
/*
Estructura del monitor
*/
struct _MonitorTP
{
	AdmonMonitor *admonMonitor;
};

// retorna  si la creación del monitor fue exitosa
int init(int nHilos, int nHilosReserva, MonitorTP** monitor){
	*monitor=(MonitorTP*) asignaMem(sizeof (MonitorTP));
	if(initAdmonMonitor(nHilos, nHilosReserva,&(*monitor)->admonMonitor)==0)
		return 0;
	else{ 
		muestraError(E_CREANDO_MONITOR);
	}
	return 0;	
}

int numeroDeHilosActivos(MonitorTP *monitor)
{
	int contActivos;
	contActivos=contadorActivos(monitor->admonMonitor);
	return contActivos;
}

int numeroDeHilosInactivos(MonitorTP *monitor){
	int contInactivos;
	contInactivos=contadorInactivos(monitor->admonMonitor);
	return contInactivos;
}
int totalDeHilos(MonitorTP *monitor){
	int contRemanente;
	contRemanente=contadorTotal(monitor->admonMonitor);
	return contRemanente;
}

/*int activarTransaccion(MonitorTP* monitorTP,
                       void* (*funcion)(void*),
                       void* argumento,
                       int prioridad);
*/
int activarTransaccion(MonitorTP *monitor, void* funcion, void* argumento, int prioridad, HiloMonitor** hiloMonitor){	
	if(transaccion(monitor->admonMonitor, funcion, argumento, prioridad, hiloMonitor)==0)
		return 0;
	else{
		muestraError(E_HACIENDO_TRANSACCION);
		
	}

	return 0;
}

int terminarTransaccion(MonitorTP *monitor, HiloMonitor *hiloMonitor){
	if(terminar(monitor->admonMonitor,hiloMonitor)==0)
		return 0;
	else
		return -1;

}

int modificarNumeroHilos(MonitorTP *monitor, int nHilos, int nHilosReserva){
	modificar(monitor->admonMonitor,nHilos,nHilosReserva);
	return 0;
}

int destruirMonitor(MonitorTP *monitor){
	if(destructor(monitor->admonMonitor)==0){
		liberaMem((void*)monitor);
		printf("Memoria Liberada con exito \n");
		return 0;
	}
	else{
		muestraError(E_DESTRUCTOR);
		return E_DESTRUCTOR;
	}

}
