#include <stdlib.h>
#include <stdio.h>
#include "colaTareas.h"

#include "admonTareas.h"

struct _ColaTareas {
  	 int prioridad;
	 HiloMonitor *hiloMonitor;
   	 ColaTareas *siguiente;
	
};


void insertarTarea(ColaTareas **tarea, int prioridad, HiloMonitor *hiloMonitor)
{
	
	ColaTareas *nuevo, *anterior;

	/* Crear un nodo nuevo */
	nuevo = (ColaTareas*)malloc(sizeof(ColaTareas));
	nuevo->prioridad = prioridad;
	nuevo->hiloMonitor=hiloMonitor;

	/* Si la tarea esta vacia */
	if(colaVacia(*tarea)==0 || (*tarea)->prioridad > prioridad) {
	/* Aadimos la tarea a continuacin del nuevo nodo */
		nuevo->siguiente = *tarea; 
	/* Ahora, el comienzo de nuestra tarea es en nuevo nodo */
		*tarea = nuevo;
	//	free (nuevo);
	}
	else {
	/* Buscar el nodo de prioridad menor a v */
		anterior = *tarea;
	/* Avanzamos hasta el ltimo elemento o hasta que el siguiente tenga 
		un prioridad mayor que v */
	while(anterior->siguiente && anterior->siguiente->prioridad <= prioridad) 
		anterior = anterior->siguiente;
	/* Insertamos el nuevo nodo despu? del nodo anterior */
	nuevo->siguiente = anterior->siguiente;
	anterior->siguiente = nuevo;
	}
}

//quita la tarea de la cola de tareas para ser ejecutada
void borrarTarea(ColaTareas **tarea, int prioridad)
{
	ColaTareas *anterior, *nodo;

	nodo = *tarea;
	anterior = NULL;
	while(nodo && nodo->prioridad < prioridad) {
		anterior = nodo; 
		nodo = nodo->siguiente;
	}
	if(!nodo || nodo->prioridad != prioridad) 
		return;
	else { /* Borrar el nodo */
		if(!anterior) /* Primer elemento */
			*tarea = nodo->siguiente;
		else  /* un elemento cualquiera */
			anterior->siguiente = nodo->siguiente;
		free(nodo);
	}   
}

int colaVacia(ColaTareas *tarea)
{
	if(tarea==NULL)
		return 0;
	else
		return 1;
}

void borrarCola(ColaTareas **tarea)
{
	ColaTareas* nodo;

	while(*tarea) {
		nodo = *tarea;
		*tarea = nodo->siguiente;
		free(nodo);
	}
}

//void mostrarCola(ColaTareas *tarea)
//{
//	ColaTareas *nodo = tarea;
//
//   	if(colaVacia(tarea)) printf("Cola vacia\n");
//	else {
//		while(nodo) {
//			printf("prioridad: %d\n", nodo->prioridad);
//			//printf("idTarea: %d \n", nodo->idTarea);
//			nodo = nodo->siguiente;
//		}
//		printf("\n");
//	}
//}
//
int initColaTareas(ColaTareas **tarea){
	*tarea = NULL;
	return 0;
}

HiloMonitor *desencolarTarea(ColaTareas **tarea){
	ColaTareas* nodo;
	HiloMonitor *hilito;
	nodo = *tarea;
	*tarea = nodo->siguiente;
	
	hilito =nodo->hiloMonitor;
	free(nodo);
//prioridad: 0
	//printf("la nueva prioridad es: %d\n", (*tarea)->prioridad);
	return hilito;
	
}

///*
//int main()
//{
//   	ColaTareas *tarea;
//   	initColaTareas(&tarea);
//	Insertar(&tarea, 20,1);
//   	Insertar(&tarea, 10,2);
//   	Insertar(&tarea, 20,3);
//   	Insertar(&tarea, 10,4);
//	Insertar(&tarea, 10,5);
//	MostrarCola(tarea);
//	return 0;
//}
//*/
