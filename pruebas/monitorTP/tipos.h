#ifdef WIN 
#include <windows.h>
#endif
#ifdef LINUX
#include <pthread.h>
#endif

#ifndef TIPOS_H
#define TIPOS_H

typedef char*	CADENA;
typedef short	BOOLEANO;
typedef	int	ENTERO;
typedef	void*	PUNTERO;
//tamaños vectores
#define MAXHILOS 256
#define MAXTAREAS 256
// BOOLEANOS
#define VERDADERO 	1
#define FALSO		0

// ESTADOS DE LA TAREA
#define LISTA		1
#define EJECUCION	2
#define TERMINADA	3
#endif 

// GENERICA PARA HILOS
#ifdef WIN
#define HILO DWORD
//generica para la fun del hilo
#define VALOR LPVOID 
#endif
#ifdef LINUX
#define HILO pthread_t
#define VALOR void*
#endif
