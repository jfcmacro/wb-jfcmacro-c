#include <stdio.h>
#include "admonMonitor.h"
#include "colaTareas.h"
#include "admonHilos.h"
#include "memoria.h"
#include "errores.h"

struct _AdmonMonitor {
  ColaTareas *cola;
  int semaforoNecesario;
  int semaforoCola;
  int semPreferencia;
  int nHilos;
  int nHilosReserva;
  AdmonHilos *administrador[MAXHILOS];
  HiloMonitor **tareas[MAXTAREAS];
};

static int actualizarMonitor(AdmonMonitor *admonMonitor, int nHilos, int nHilosReserva);
//
int initAdmonMonitor(int nHilos, int nHilosReserva,AdmonMonitor **monitor){
	int i;
	*monitor =(AdmonMonitor*) asignaMem((sizeof (AdmonMonitor)));
	if(initColaTareas(&(*monitor)->cola)==0){
		(*monitor)->semaforoCola=1;//el primero que llegue tiene derecho a entrar
		(*monitor)->semPreferencia=0; //semforo que da preferencia los escritores
		printf("Usted ha decidido crear: %d Hilos en Reserva, y en total el sistema soportará: %d\n", nHilosReserva, nHilos);
		(*monitor)->nHilos=nHilos;
		(*monitor)->nHilosReserva=nHilosReserva;

		for(i=0;i<nHilosReserva;i++){
			AdmonHilos *admon;
			if (initAdmonHilos(i,&admon,*monitor)==0){
				(*monitor)->administrador[i]=admon;
			}

			else{
				return -1;
			}
		}
	//se crea solo si es necesario
		for(i=nHilosReserva; i<nHilos; i++){
			AdmonHilos *admon;
			if (initAdmonHilosRemanentes(i,&admon,*monitor)==0){
				(*monitor)->administrador[i]=admon;
			}
			else{
				return -1;
			}
		}
		//ojo cambio
		for(i=0; i<MAXTAREAS; i++){
			(*monitor)->tareas[i]=NULL;
		}
    return 0;
	}
	else {
		return -1;
	}
}

int contadorActivos(AdmonMonitor *monitor)
{
	int contactivos=0;
	int i;
	AdmonHilos *admon;
	for(i=0; i<monitor->nHilos; i++){
		if(monitor->administrador[i]!='\0'){
			admon=monitor->administrador[i];
			if(obtenerEstadoHilo(admon)==1){
				contactivos++;
			}
		}
	}
	//printf("el numero de activos es: %d\n", contactivos);
	return contactivos;
}

int contadorInactivos(AdmonMonitor *monitor){
	int contInactivos=0;
	int i;
	AdmonHilos *admon;
	for(i=0; i<monitor->nHilosReserva; i++){
		if(monitor->administrador[i]!='\0'){
			admon=monitor->administrador[i];
			if(obtenerEstadoHilo(admon)==0){
				contInactivos++;
			}
		}
	}
	//printf("el numero de inactivos es: %d\n", contInactivos);
	return contInactivos;
}
int contadorTotal(AdmonMonitor *monitor){
	int contRemanente=0;
	int i;
	for(i=monitor->nHilosReserva; i<monitor->nHilos; i++){
		if(monitor->administrador[i]!='\0')
			contRemanente++;
	}
	contRemanente +=monitor->nHilosReserva ;
	return contRemanente;
}

//retorna el hilo sobre el cual se va a ejecutar el hilo
static int existeHiloReserva(AdmonMonitor *monitor){
	int i=0;
	AdmonHilos *admon;
	BOOLEANO noAsignado= FALSO;
	for(i=0; i<monitor->nHilosReserva; i++){
		if(monitor->administrador[i]!='\0'){
			admon=monitor->administrador[i];
			if(obtenerEstadoHilo(admon)==FALSO){
				return (i+1);
			}
		}
	}
	printf("no hay hilos en reserva disponibles\n");
	return 0;
}

static int existeHiloRemanente(AdmonMonitor *monitor){
	int i=0;
	AdmonHilos *admon;
	BOOLEANO noAsignado= FALSO;
//	int h;
	//printf("voy a recorrer desde %d hasta %d: \n",monitor->nHilosReserva, monitor->nHilos);
	for(i=monitor->nHilosReserva; i< monitor->nHilos; i++){
		if(monitor->administrador[i]!='\0'){
			admon=monitor->administrador[i];
			if(obtenerEstadoHilo(admon)==FALSO){
				//printf("el hilo %d esta inactivo: %d \n",i,obtenerEstadoHilo(admon));
				return (i+1);
			}
		}
	}
	printf("no hay hilos remanentes disponibles\n");
	return 0;
}
//
int transaccion(AdmonMonitor *monitor, void* funcion, void* argumento, int prioridad, HiloMonitor** hiloMonitor){	
	//SI HAY POR LO MENOS UN ELEMENTO EN LA COLA ENTRO DIRECTO A LA COLA Y NO COMPRUEBO NADA
	AdmonHilos *admon;
	int i=0;
	BOOLEANO noAsignado=FALSO;
	//encontramos un espacio en el vector tareas libre
	while (i<MAXTAREAS && noAsignado==FALSO){
		if(monitor->tareas[i]==NULL){
			monitor->tareas[i]=hiloMonitor;
			noAsignado=VERDADERO;
		}
		i++;
	}
	if (i==MAXTAREAS){
		printf("no hay espacio para más tareas");
	}

	else{
		
		//crea un admonTareas para esa tarea
		if(initAdmonTareas(funcion,argumento,&prioridad,&(*hiloMonitor))==0){
			
			//busca un hilo en reserva libre 
			int libre= existeHiloReserva(monitor);
			
			if(libre!=0){
				printf("la tarea se ejecutara sobre el hilo: %d\n", (libre-1));
				admon =monitor->administrador[libre-1];
				asignarTareaHilo(*hiloMonitor,admon);
			}
			else
			{	
				//devolver el hilo remanente sobre el que voy a eje la tarea
				libre = existeHiloRemanente(monitor);
				if(libre!=0){
					printf("la tarea se ejecutara sobre el hilo remanente: %d\n", (libre-1));
					admon=monitor->administrador[libre-1];
					if(asignarTareaHilo(*hiloMonitor,admon)!=0)
						return -1;

				}
				else {
				//encolar la tarea
					printf("la tarea será encolada\n");
					encolarTarea(monitor,prioridad,*hiloMonitor);
					//insertarTarea(&monitor->colaTareas,prioridad,(i-1),*hiloMonitor);
					//mostrarCola(monitor->colaTareas);
				}
				
			}
		}
		else{
			return -1;
			
		}
	}

return 0;
}
int terminar(AdmonMonitor *monitor, HiloMonitor *hiloMonitor){
	int i;
	for(i=0; i<MAXTAREAS; i++){
		if(monitor->tareas[i]!='\0'){
			if(*monitor->tareas[i]==hiloMonitor){
				if(estadoTarea(hiloMonitor)==3){
					monitor->tareas[i]='\0';
					liberaMem(( void*)hiloMonitor);
					//printf("memoria liberada con exito\n");
					return 0;
				}
				else{
					printf("la tarea no ha terminado, intente de nuevo más tarde\n");
					return -1;
				}
			}
		}
	}
	muestraError(E_HILO_MONITOR_NOEXISTE);
	
	return 0;

}



int modificar(AdmonMonitor *monitor,int nHilos,int nHilosReserva){
	int correr;
	int crearReserva;
	int crearRemanentes;
	int i,j;
	if(nHilos>monitor->nHilos){
		//me dice en cuanto se amplio el vector de los hilos
		correr = nHilos-monitor->nHilos;
		j=1;
		for(i=monitor->nHilosReserva; i<monitor->nHilos; i++){
			printf("voy a correr el hilo de la pos %d a la pos %d\n",nHilos-j-correr,nHilos-j);
			monitor->administrador[nHilos-j]=monitor->administrador[nHilos-j-correr];
			j++;
		}
		if(nHilosReserva>monitor->nHilosReserva){
			
			crearReserva = nHilosReserva - monitor->nHilosReserva;
			for(i=1; i<=crearReserva; i++){
				AdmonHilos *admon;
				if (initAdmonHilos(i,&admon,monitor)==0){
					printf("cree un reserva en la pos: %d\n",(nHilosReserva-i));
					monitor->administrador[nHilosReserva-i]=admon;
				}

				else{
					return -1;
				}
			}
			
			crearRemanentes=correr-crearReserva;
			//printf("voy a crear %d hilos remanentes\n", crearRemanentes);
			for(i=0; i<crearRemanentes; i++){
				AdmonHilos *admon;
				if (initAdmonHilosRemanentes(i,&admon,monitor)==0){
					printf("cree un remanente en la pos: %d\n",nHilosReserva+i);
					monitor->administrador[nHilosReserva+i]=admon;
				}

				else{
					return -1;
				}
			}
			actualizarMonitor(monitor,nHilos,nHilosReserva);
		
		}
		//cuando nhilosReserva es < a nhilosReserva
		else{
			if(nHilosReserva<monitor->nHilosReserva){
				crearReserva=monitor->nHilosReserva-nHilosReserva;
				for(i=crearReserva; i<=monitor->nHilosReserva;i++){
					printf("el hilo que estaba en la pos: %d ahora es remanente\n",i);
					cambiarTipoHilo(monitor->administrador[i-1]);
				}
				crearReserva=nHilos-monitor->nHilos;
				for(i=crearReserva; i<nHilos; i++){
					AdmonHilos *admon;
					if (initAdmonHilosRemanentes(i,&admon,monitor)==0){
						printf("cree un remanente en la pos: %d\n",nHilosReserva+i);
						monitor->administrador[nHilosReserva+i]=admon;
					}

					else{
						return -1;
					}
					
				}
				actualizarMonitor(monitor,nHilos,nHilosReserva);
			}
			else{
				crearReserva=nHilos-monitor->nHilos;
				for(i=crearReserva; i<nHilos; i++){
					AdmonHilos *admon;
					if (initAdmonHilosRemanentes(i,&admon,monitor)==0){
						printf("cree un remanente en la pos: %d\n",nHilosReserva+i);
						monitor->administrador[nHilosReserva+i]=admon;
					}

					else{
						return -1;
					}
				}
				actualizarMonitor(monitor,nHilos,nHilosReserva);
			}
		}
	}
	else{
		if (nHilos< monitor->nHilos){
			if(nHilosReserva>monitor->nHilosReserva){
				//abro espacio para los nuevos reserva
				correr = monitor->nHilos-nHilos;
				j=1;
				for(i=monitor->nHilosReserva; i<monitor->nHilos; i++,j++){
					printf("voy a correr el hilo de la pos %d a la pos %d\n",(monitor->nHilos)-j,(monitor->nHilos)-j+correr);
					monitor->administrador[(monitor->nHilos)-j+correr]=monitor->administrador[(monitor->nHilos)-j];
					
				}
				//crearReserva=monitor->nHilosReserva-nHilosReserva;
				for(i=monitor->nHilosReserva; i<nHilosReserva; i++){
					AdmonHilos *admon;
					if (initAdmonHilos(i,&admon,monitor)==0){
						printf("cree un reserva en la pos: %d\n",i);
						monitor->administrador[i]=admon;
					}

					else{
						return -1;
					}
				}
				for(i=(monitor->nHilos)+correr; i>=nHilos+1; i--){
					printf("el hilo que estaba en la pos %d, ya no es necesario\n", i-1);
					if(obtenerEstadoHilo(monitor->administrador[i-1])==0){
       					//liberaMem((void*)monitor->administrador[i-1]);
						monitor->administrador[i-1]=NULL;
						correr--;
					}

 					else{
						if(obtenerEstadoHilo(monitor->administrador[i-1])==1)
						cambiarNecesario(monitor->administrador[i-1]);
						else
							monitor->administrador[i-1]=NULL;
					}
				}

				monitor->semaforoNecesario=correr;
				actualizarMonitor(monitor,nHilos,nHilosReserva);

			}
			else{
				correr = monitor->nHilos-nHilos;
				if(nHilosReserva<monitor->nHilosReserva){
					
					for(i=nHilosReserva; i<monitor->nHilosReserva;i++){
						printf("el hilo que estaba en la pos: %d ahora es remanente\n",i);
						cambiarTipoHilo(monitor->administrador[i]);
					}
					for(i=monitor->nHilos; i>nHilos; i--){
						printf("el hilo que estaba en la pos %d, ya no es necesario\n", i-1);
						if(obtenerEstadoHilo(monitor->administrador[i-1])==0){
						//liberaMem((void*)monitor->administrador[i-1]);
						monitor->administrador[i-1]=NULL;
						correr--;
					}
					else{
						cambiarNecesario(monitor->administrador[i-1]);

					}
					//	cambiarNecesario(monitor->administrador[i-1]);
					}
					monitor->semaforoNecesario=correr;
					actualizarMonitor(monitor,nHilos,nHilosReserva);
				}
				else{
				//son iguales
					correr=monitor->nHilos-nHilos;
					for(i=monitor->nHilos; i>nHilos; i--){
						printf("el hilo que estaba en la pos %d, ya no es necesario\n", i-1);
						if(obtenerEstadoHilo(monitor->administrador[i-1])==0){
						//liberaMem((void*)monitor->administrador[i-1]);
							monitor->administrador[i-1]=NULL;
							correr--;
					}
					else{
						cambiarNecesario(monitor->administrador[i-1]);

					}
						//cambiarNecesario(monitor->administrador[i-1]);
					}
					monitor->semaforoNecesario=correr;
					actualizarMonitor(monitor,nHilos,nHilosReserva);
				}
			}
		}
		else{
			//nHilos= monitor->nHilos
			
			if(nHilosReserva>monitor->nHilosReserva){
				//abro espacio para los nuevos reserva
				correr=nHilosReserva-monitor->nHilosReserva;
				j=1;
				for(i=monitor->nHilosReserva; i<monitor->nHilos; i++,j++){
					printf("voy a correr el hilo de la pos %d a la pos %d\n",(monitor->nHilos)-j,(monitor->nHilos)-j+correr);
					monitor->administrador[(monitor->nHilos)-j+correr]=monitor->administrador[(monitor->nHilos)-j];
				
				}
				for(i=(monitor->nHilos)+correr; i>=nHilos+1; i--){
					printf("el hilo que estaba en la pos %d, ya no es necesario\n", i-1);
					if(obtenerEstadoHilo(monitor->administrador[i-1])==0){
						//liberaMem((void*)monitor->administrador[i-1]);
						monitor->administrador[i-1]=NULL;
						correr--;
					}
					else{
						cambiarNecesario(monitor->administrador[i-1]);

					}
					
				}
				monitor->semaforoNecesario=correr;
				actualizarMonitor(monitor,nHilos,nHilosReserva);
			}
			else{
				if(nHilosReserva<monitor->nHilosReserva){
					for(i=nHilosReserva; i<monitor->nHilosReserva;i++){
						printf("el hilo que estaba en la pos: %d ahora es remanente\n",i);
						cambiarTipoHilo(monitor->administrador[i]);
					}
				}
				actualizarMonitor(monitor,nHilos,nHilosReserva);
			}
		}
	}
	return 0;

}

static int actualizarMonitor(AdmonMonitor *admonMonitor, int nHilos, int nHilosReserva){
	admonMonitor->nHilos= nHilos;
	admonMonitor->nHilosReserva=nHilosReserva;
	return 0;
}
int encolarTarea(AdmonMonitor *admonMonitor,int prioridad,HiloMonitor *hiloMonitor){
	signalPreferencia(admonMonitor);
	while(admonMonitor->semaforoCola==0){
	printf("Esperando permiso para insertar tarea\n");
	}
	semSignalCola(admonMonitor);
	insertarTarea(&admonMonitor->cola,prioridad,hiloMonitor);
	//mostrarCola(admonMonitor->cola);
	signalPreferencia(admonMonitor);
	semSignalCola(admonMonitor);
	return 0;
}
//int imprimirCola(AdmonMonitor *admonMonitor){
//	printf("termino la tarea y hay en cola: \n");
//	mostrarCola(admonMonitor->cola);
//}
int hayTareasCola(AdmonMonitor *admonMonitor){
	while(admonMonitor->semaforoCola==0 || admonMonitor->semPreferencia==1){
	printf("Esperando permiso para leer tarea\n");
	}
	semSignalCola(admonMonitor);
	//si la cola esta vacia no habrán peticiones de obtener tarea, se pueden hacer otras operaciones
	if( colaVacia(admonMonitor->cola)==0){
		// si la cola esta vacia doy permiso para que otro entre
		semSignalCola(admonMonitor);
		return 0;
	}
	// no doy signal porque voy a retirar el elemento
	else{
		return 1;
	}
	//return 0;
}
void* obtenerTareaCola(AdmonMonitor *admonMonitor){
	void *temp;
	temp=(void*)desencolarTarea(&admonMonitor->cola);
	semSignalCola(admonMonitor);
	return temp;
	
}
int signalEliminarAdmon(AdmonHilos *admon, AdmonMonitor *monitor){
	int i;
	// me recorro el vector de admones para ver cual es que debo liberar
	for(i=0; i<monitor->nHilos; i++){
		if(monitor->administrador[i]==admon){
			printf("hola entre");
			liberaMem((void*)admon);
			monitor->semaforoNecesario--;
			return 0;
		}
	}
	return -1;
}
int signalPreferencia(AdmonMonitor *admonMonitor){
	if(admonMonitor->semPreferencia==1)
		admonMonitor->semPreferencia=0;
	else
		admonMonitor->semPreferencia=1;
	return 0;
}
int semSignalCola(AdmonMonitor *admonMonitor){
	if (admonMonitor->semaforoCola==0)
		admonMonitor->semaforoCola=1;
	else
		admonMonitor->semaforoCola=0;
	return 0;
}


int destructor(AdmonMonitor *admonMonitor){
	while(contadorActivos(admonMonitor)>0){
	}
	printf("destruyendo monitor \n");
	liberaMem((void*)admonMonitor);
	return 0;
}
