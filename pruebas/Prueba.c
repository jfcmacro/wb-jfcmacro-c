#include <stdio.h>

enum MonitorTP_Errores { NoError = 0, 
                             E_MonitorInvalido = -1,
                             E_CreandoMonitor = -2,
                             E_ParametroIncorrecto = -3,
                             E_HiloMonitorNoExiste = -4,
                             E_HiloMonitorTerminado = -5,
                             E_ErrorCreandoHilo = -6,
                             E_PrioridadIncorrecta = -7,
                             E_Sincronizacion = -8,
                             E_OtroError = -9 };

int
main(){

   enum MonitorTP_Errores me = NoError;

   printf("%d\n", me);


}
