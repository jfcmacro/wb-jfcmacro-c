#include "monitorTP.h"
#include "tareas.h"
#include "hiloMonitor.h"
#include "util.h"
#include <stdio.h>
int main(){
	char*respuesta;
	MonitorTP *p;
	MonitorTP *q;
	void *arg;
	void *arg2;
	HiloMonitor *hiloM;
	HiloMonitor *hiloM2;
	HiloMonitor *hiloM3;
	HiloMonitor *hiloM4;
	int argumento;
	int argumento2;
	argumento=5;
	argumento2=3;
	arg = &argumento;
	arg2= &argumento2;

	init (0,0,&p);
    numeroDeHilosActivos(p);
	numeroDeHilosInactivos(p);
	activarTransaccion(p,&funcion1,arg,0,&hiloM);
	activarTransaccion(p,&funcion3,arg2,8,&hiloM2);
	respuesta=(char*)obtenerEstado(hiloM2);
	printf("RESPUESTA: %s\n",respuesta);
	
	modificarNumeroHilos(p,1,1);
	activarTransaccion(p,&funcion2,arg2,5,&hiloM3);
	activarTransaccion(p,&funcion3,arg,5,&hiloM4);
	respuesta=(char*)obtenerEstado(hiloM4);
	printf("RESPUESTA: %s\n",respuesta);
	terminarTransaccion(p,hiloM4);
	terminarTransaccion(p,hiloM2);
	destruirMonitor(p);
	
	printf("\n\nTermino");
	getch();
		
}

