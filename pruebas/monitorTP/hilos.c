#include "hilos.h"
#include "tipos.h"
#ifdef WIN
#include <windows.h>
#endif
#include <stdio.h>
// retorna cero si se creo bien el hilo, de lo contrario un valor

static void * funcionHilo(VALOR informacion){
	InfoHilo *info= (InfoHilo*) informacion;
	//printf(" =):\n");
	while (hiloNecesario(info)==VERDADERO){
		if(semaforoCero(info)==1){
			printf("me asignaron tarea =):\n");
			ejecutarTarea(info);
			semaforoSignal(info);
			//break;
		}
	}
	return (void*)0;
}

#ifdef WIN
//crea los hilos de reserva
int crearHilo(int *idHilo, HILO *hilo, InfoHilo *informacion){
	CreateThread( 0, // es un apuntador al atributo  de seguridad
		0, //tamaño de la pila , 0 para que tome el valor por omision
		( LPTHREAD_START_ROUTINE)funcionHilo, //apuntador a la fun que ejecutara el hilo
		(LPVOID)(informacion), // apuntador al parametro que le vamos a entregar a la fun hilo
		0, //el proceso comienza a ejecutarse de inmediato
		hilo);//
	
	return 0;
}
#endif

#ifdef LINUX
//crea los hilos de reserva
int crearHilo(int *idHilo, HILO *hilo, InfoHilo *informacion){
	
	return pthread_create(hilo, // hilo -> identificadoe del hilo en ejecucion
	 NULL, // atributos del hilo
	funcionHilo,// apuntador a la funcion en la cual se ejecutara el hilo
	(void *) (informacion)); // argumento que sera pasado a la fun que ejecutara el hilo
	return 0;
}
#endif




