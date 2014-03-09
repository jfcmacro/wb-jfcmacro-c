#include "admonHilos.h"
#include "tipos.h"
#include "errores.h"
#include "infoHilo.h"
#include "admonMonitor.h"
#include "memoria.h"
#include <stdio.h>

struct _AdmonHilos
{
    BOOLEANO necesario; // indica si el hilo aún es necesario para el MonitorTP: 1 si es necesario 0 si no es necesario
    BOOLEANO activo; // indica: 0 si es si no esta activo y 1 si esta activo
    int idAdmon;
    BOOLEANO reserva;//1 Reserva 0 remanente
    HILO *hilo;
    HiloMonitor *hiloMonitor;
    InfoHilo *informacion;
    AdmonMonitor *admonMonitor;
    int semHilo;
    int semPreferencia;
};

int crearAdmonHilos(int idHilo, AdmonHilos **admon, AdmonMonitor *admonMonitor){
	*admon = (AdmonHilos*) asignaMem((sizeof (AdmonHilos)));
	(*admon)->necesario=VERDADERO;
	(*admon)->activo=FALSO; //inactivo
	(*admon)->idAdmon=idHilo;
	(*admon)->admonMonitor= admonMonitor;
	(*admon)->semHilo=1;
	(*admon)->semPreferencia=0;
	if(initInfoHilo(&(*admon)->informacion,*admon)==0)
		return 0;
	else
		return -1;
}
//// retorna cero si la creación del administrador del hilo fue creado con exito
int initAdmonHilos (int idHilo, AdmonHilos **admon,AdmonMonitor *admonMonitor ){
	if (crearAdmonHilos(idHilo,&*admon,admonMonitor)==0){
		(*admon)->reserva=VERDADERO;
		if(crearHilo(&(*admon)->idAdmon,&(*admon)->hilo, (*admon)->informacion)==0){
			if(hayTareasCola((*admon)->admonMonitor)==1){
				(*admon)->hiloMonitor = (HiloMonitor*)obtenerTareaCola((*admon)->admonMonitor);
				//	imprimirCola(admon->admonMonitor);
				printf("desencolando tarea\n");
				asignarTareaHilo((*admon)->hiloMonitor,*admon);
			}
			return 0;
		}
		else{
			muestraError(E_ERROR_CREANDO_HILO);
			return E_ERROR_CREANDO_HILO; 
		}
	}
	else
		return -1;
}
//
////inicializa los hilos remanentes
int initAdmonHilosRemanentes(int idHilo, AdmonHilos **admon,AdmonMonitor *admonMonitor){
	if(crearAdmonHilos(idHilo,&*admon,admonMonitor)==0){
		(*admon)->reserva=FALSO;
		if(hayTareasCola((*admon)->admonMonitor)==1){
			(*admon)->hiloMonitor = (HiloMonitor*)obtenerTareaCola((*admon)->admonMonitor);
			//	imprimirCola(admon->admonMonitor);
			printf("desencolando tarea\n");
			asignarTareaHilo((*admon)->hiloMonitor,*admon);
		}
		return 0;
	}
	else
		return E_ERROR_CREANDO_HILO; //ERROR CREANDO HILO
	
}
//
//
//retorna si el hilo esta activo(ejecutando una tarea) o esta inactivo
//verdadero=1;
int obtenerEstadoHilo(AdmonHilos *admon){
	int temp;
	while(admon->semHilo==0 || admon->semPreferencia==1){
	printf("Esperando permiso para leer estado hilo\n");
	}
	semSignalHilo(admon);
	temp=(admon->activo);
	semSignalHilo(admon);
	return temp;
}

//le asigna una tarea a un hilo de reserva disponible
int asignarTareaHilo(HiloMonitor *hiloMonitor,AdmonHilos *admon){
		//admon->activo=VERDADERO;
		void * funcion =(void*) obtenerFuncion(hiloMonitor);
		void * argumento=(void*)obtenerArg(hiloMonitor);
		//printf("llegue\n");
		if(admon->reserva==FALSO){
			admon->necesario=VERDADERO;
			crearHilo(&admon->idAdmon,&admon->hilo, admon->informacion);
		}
		admon->hiloMonitor=hiloMonitor;
		initFuncion(funcion,argumento,admon->informacion);
		cambiarEstadoTarea(hiloMonitor);
		semaforoSignal(admon->informacion);
		return 0;
}

int modificarEstadoHilo(AdmonHilos *admon){

	if(admon->activo==VERDADERO){
		cambiarEstadoTarea(admon->hiloMonitor);
		signalPreferenciaHilos(admon);
		while(admon->semHilo==0){
		printf("Esperando permiso para modificar el estado del hilo\n");
		}
		semSignalHilo(admon);
		admon->activo=FALSO;
		signalPreferenciaHilos(admon);
		semSignalHilo(admon);
		// si el estado del hilo es no necesario es porque decicidieron eliminiarlo (modificar numero de hilos)
		if (admon->necesario==VERDADERO){
			if(admon->reserva==FALSO){
				cambiarNecesario(admon);
			}
			if(hayTareasCola(admon->admonMonitor)==1){
				admon->hiloMonitor = (HiloMonitor*)obtenerTareaCola(admon->admonMonitor);
			//	imprimirCola(admon->admonMonitor);

				printf("desencolando tarea\n");
				asignarTareaHilo(admon->hiloMonitor,admon);
			}
		}
		// si el estdo es que no es necesario, hago un signal para que me eliminien
		else{

			signalEliminarAdmon(admon,admon->admonMonitor);
		}
	}
	//el hilo no estaba haciendo tarea y le voy a poner una
	else{
		if(admon->activo==FALSO){
			//semaforo que me da permiso de escribir
			while(admon->semHilo==0){
			printf("Esperando permiso para modificar el estado del hilo\n");
			}
			semSignalHilo(admon);
			admon->activo=VERDADERO;
			semSignalHilo(admon);
		}
		else{
			printf("No se puede modificar el estado, la direccion es invalida (admonHilos)\n");
		}
	}

	return 0;
}

int signalPreferenciaHilos(AdmonHilos *admon){
	if(admon->semPreferencia==1)
		admon->semPreferencia=0;
	else
		admon->semPreferencia=1;
	return 0;
}
int semSignalHilo(AdmonHilos *admon){
	if (admon->semHilo==0)
		admon->semHilo=1;
	else
		admon->semHilo=0;
	return 0;
}
//

int esNecesario(AdmonHilos *admon){
	return (admon->necesario);
}

int cambiarNecesario(AdmonHilos *admon){
	admon->necesario=FALSO;
	return 0;
}


int cambiarTipoHilo(AdmonHilos *admon){
	admon->reserva=FALSO;
	return 0;
}
