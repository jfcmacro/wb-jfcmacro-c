#include "tipos.h"
#include "infoHilo.h"
#include "admonHilos.h"

struct _InfoHilo
{
	int semaforo;
	void* (*funcion)(void *);
	void* argumento;
	AdmonHilos *admon;
	
};

//Inicializa el semaforo y recibe un apuntador a la estructura Administrador de Hilos
int initInfoHilo(InfoHilo **informacion, AdmonHilos *admon){
	
	*informacion = (InfoHilo*) asignaMem((sizeof (InfoHilo)));
	(*informacion)->semaforo=0;
	(*informacion)->admon=admon;
	return 0;
}

//función que indica si el semaforo está en cero
int semaforoCero(InfoHilo *informacion){
	if(informacion->semaforo==0)
		return 0;
	else{
		if(informacion->semaforo==1)
			return 1;
		else
			printf("no se sabe en que estado esta el semaforo\n");
	}
		
return 0;	
}
//cambia el estado del semaforo (0 o 1)
int semaforoSignal(InfoHilo *informacion){
	if(informacion->semaforo==0){ //el hilo no tenia tarea asignada
	//	printf("el semaforo anuncia una nueva tarea\n");
		informacion->semaforo=1;
		modificarEstadoHilo(informacion->admon);
		
	}
	else{
		if(informacion->semaforo==1){
			informacion->semaforo=0;
			modificarEstadoHilo(informacion->admon);
		}
		else
			printf("Direccion de Info Hilo invalida\n");
	}
	return 0;
}

//ejecuta la tarea 
int ejecutarTarea(InfoHilo *informacion){
	informacion->funcion(informacion->argumento);
	return 0;
}

//incializa la función y el argumento para ser ejecutados por el hilo
int initFuncion(void* funcion, void* argumento, InfoHilo *informacion){
	informacion->funcion=funcion;
	informacion->argumento=argumento;
	return 0;
}

int hiloNecesario(InfoHilo *informacion){
	return (esNecesario(informacion->admon));
	//return 0;
}
