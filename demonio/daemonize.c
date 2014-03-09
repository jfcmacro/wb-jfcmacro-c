#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <fcntl.h>

void
daemonize(const char *cmd)
{
  int i;
  pid_t pid;
  struct rlimit rl;
  char filename[256];

  /*
   * Limpia la mascara de creacion de archivos
   */
  umask(0);

  /*
   * Obtiene el maximo numero de archivos que pueden ser abiertos 
   */
  if (getrlimit(RLIMIT_NOFILE,2 &rl) < 0)
    exit(0);

  /*
   * Llega a ser lider de sesion para cerrar nuestra terminal de control
   */
  if ((pid = fork()) < 0)
    exit(0);
  else if (pid != 0)
    exit(0); /* Termina el padre */
  setsid();

  /*
   * Asegura que las aperturas posteriores no localicen terminales de
   * control
   */
  sigset(SIGHUP, SIG_IGN);

  if ((pid = fork()) < 0)
    exit(0);
  else if (pid != 0)
    exit(0);
  
  /*
   * Cierre todos los descriptores abiertos
   */
  if (rl.rlim_max == RLIM_INFINITY)
    rl.rlim_max = 1024;
  
  for (i = 0; i < rl.rlim_max; i++)
    close(i);

  /*
   * Cambia el directorio de trabajo actual al directorio raiz
   */

  if (chdir("/") < 0) 
    exit(0);

  /*
   * Liga los descriptores 0, 1 y 2 al dispositivo /dev/null
   */
  if ((i = open("/dev/null", O_RDWR)) == 0) {
    
    dup(0);
    dup(0);
  }
}
