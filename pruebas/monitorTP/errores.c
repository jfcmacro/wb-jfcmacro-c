#include <stdio.h>
#include "errores.h"
void muestraError(int error){
 switch(error){
	case -1: printf("Error 1: El apuntador al que se referencia el monitor es invalido\n");break;
	case -2: printf("Error 2: Error creando el monitor\n"); break;
	case -3: printf("Error 3: Parametro incorrecto\n"); break;
	case -4: printf("Error 4: El apuntador al que se referencia el hilo monitor no existe\n"); break;
	case -5: printf("Error 5: Fallo en la creación del hilo\n"); break;
	case -6: printf("Error 6: La prioridad ingresada es incorrecta\n"); break;
	case -7: printf("Error 7: Error en la sincronización\n");break;
	case -8: printf("Error 8: Función nula\n"); break;
	case -9: printf("Error 9: Transaccion no exitosa\n");break;
	case -10: printf("Error 10: Error destruyendo el monitor\n");break;
	}
}
