#include "hiloMonitor.h"

/*retorna el estado de la tarea:
Lista: tarea en cola lista para se ejcutada
Ejecución: tarea que se está ejecutando
Terminada: Tarea finalizada*/

char * obtenerEstado(HiloMonitor *hiloMonitor){
	int h=estadoTarea(hiloMonitor);
	char *rta;
	switch (h){
		case 1: 
			rta="La tarea esta esperando a ser Ejecutada\n"; break;
		case 2:
			rta= "La tarea esta siendo Ejecutada\n";break;
		case 3: 
			rta="la tarea ya termino\n";break;
		default:
			rta="no sabemos\n";break;
		
	};
	return (rta);
	
}

//devuelve cero si la tarea esta en ejecución
int estaActivo(HiloMonitor *hiloMonitor){
	int h=estadoTarea(hiloMonitor);
	if(h==2){
		return 0;
	}
	else{
		return -1;
	}
}

//devuelve cero si la tarea esta lista o esta esperando a ser ejecutada 
int estaInactivo(HiloMonitor *hiloMonitor){
	int h=estadoTarea(hiloMonitor);
		if(h==1){
			return 0;
		}
		else{
			return -1;
		}
}

//devuelve cero si la tarea termino
int haTerminado(HiloMonitor *hiloMonitor){
	int h=estadoTarea(hiloMonitor);
		if(h==3){
			return 0;
		}
		else{
			return -1;
		}
}
