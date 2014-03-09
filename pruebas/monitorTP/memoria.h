#ifndef MEMORIA_H
#define MEMORIA_H
/* declaracion de funciones para el manejo de memoria */

// asigna memoria y retorna el apuntador hacia donde la asigno
// en caso de error retorna el apuntador nulo
void* asignaMem( int cantidad);


// libera la memoria apuntada
void liberaMem( void* mem);

// reasigna memoria y retorna el apuntador hacia donde se 
// asigno la nueva memoria, en caso de error retorna
// un apuntador hacia nulo
//void* memReasigna( void* mem, int cantidad);
#endif
