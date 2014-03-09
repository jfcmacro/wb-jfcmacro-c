
/* implementacion de las funciones para el manejo de memoria */
#include "memoria.h"
/*
#ifdef WIN
#include <windows.h>
#endif
*/
// asigna memoria y retorna el apuntador hacia donde la asigno
// en caso de error retorna el apuntador nulo
void* asignaMem( int tamanho){

	void* memoria;
//	#ifdef LINUX
		memoria = (void*) malloc(tamanho);
/*	#endif
	#ifdef WIN
		memoria = (void*) GlobalAlloc( GPTR, tamanho);
	#endif
*/
	return memoria;
}

// libera la memoria apuntada
void liberaMem( void* memoria){

//	#ifdef LINUX
		free( memoria);
		printf("memoria liberada con exito\n");
/*	#endif
	#ifdef WIN
		GlobalFree( memoria);
	#endif*/
}

/*
// reasigna la memoria y retorna el apuntador hacia donde
// se asigno la nueva memoria, en caso de error retorna 
// el apuntador nulo
void* memReasigna( void* mem, int cantidad){

	void* memRet;
	#ifdef UNIX
		memRet = (void*) realloc( mem, cantidad);
	#endif
	#ifdef WIN
		memRet = (void*) GlobalReAlloc( mem, cantidad, GMEM_MOVEABLE);
	#endif

	return memRet;
}
*/
