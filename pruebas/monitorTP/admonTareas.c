#include "admonTareas.h"
#include "tipos.h"
#include "errores.h"
#include "memoria.h"
#include <stdio.h>

struct _HiloMonitor
{
	int estado; // activa (ejecución)
	void *funcion;
	void *argumento;
	//int *prioridad;
	int semTareas;
	int semPreferencia; //semaforo que da preferencia al que vaya a modificar el estado de la tarea
};

//inicializa la estructura del hilo monitor
int initAdmonTareas(void* funcion, void* argumento, int* prioridad, HiloMonitor **hiloMonitor){
	*hiloMonitor= (HiloMonitor*)asignaMem(sizeof(HiloMonitor));
	(*hiloMonitor)->estado=LISTA;
	(*hiloMonitor)->funcion=funcion;
	(*hiloMonitor)->argumento=argumento;
	//(*hiloMonitor)->prioridad=(int*)&prioridad;
	(*hiloMonitor)->semTareas=1;
	(*hiloMonitor)->semPreferencia=0;
	return 0;
}

//devuelve el estado de la tarea 1:activa - activarTransaccion(p,&funcion3,arg,5,&hiloM2);: Inactiva
int estadoTarea(HiloMonitor* hiloMonitor){
	int tempo;
	while(hiloMonitor->semTareas==0 || hiloMonitor->semPreferencia==1){
	printf("Esperando permiso para leer tarea\n");
	}
	semSignalTarea(hiloMonitor);//pone en cero el semaforo
	tempo=hiloMonitor->estado;
	semSignalTarea(hiloMonitor);
	return tempo;
	
}

////Cambia el estado de la tarea
int cambiarEstadoTarea(HiloMonitor *hiloMonitor){
	signalPreferenciaTarea(hiloMonitor);
	while(hiloMonitor->semTareas==0){
	printf("Esperando permiso para cambiar estado de la tarea\n");
	}
	semSignalTarea(hiloMonitor);

	if(hiloMonitor->estado==LISTA){
		hiloMonitor->estado=EJECUCION;
	}
	else{
		if(hiloMonitor->estado==EJECUCION){
			hiloMonitor->estado=TERMINADA;
		}
		else{
		printf("el estado de la tarea No es valido\n");
		}
	}
		semSignalTarea(hiloMonitor);
		signalPreferenciaTarea(hiloMonitor);
		return 0;
}
int signalPreferenciaTarea(HiloMonitor *hiloMonitor){
	if(hiloMonitor->semPreferencia==1)
		hiloMonitor->semPreferencia=0;
	else
		hiloMonitor->semPreferencia=1;
	return 0;
}
int semSignalTarea(HiloMonitor *hiloMonitor){
	if (hiloMonitor->semTareas==0)
		hiloMonitor->semTareas=1;
	else
		hiloMonitor->semTareas=0;
	return 0;
}

void * obtenerFuncion(HiloMonitor *hiloMonitor){
	return hiloMonitor->funcion;
}
void * obtenerArg(HiloMonitor *hiloMonitor){
	return hiloMonitor->argumento;
}
