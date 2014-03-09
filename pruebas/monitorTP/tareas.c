#include "util.h"

void *funcion1(){
	dormir(2);
	printf("yo soy la funcion uno\n");
}
void *funcion2(void *argumento){
	printf("yo soy la funcion dos\n");
}
void *funcion3(void *argumento){
	int *j= (int*)argumento;
	int h = (*j)*(*j);
	printf("el argumento en la funcion es: %d\n",*j);
	printf("el resultado es: %d\n", h);
}
