#include <unistd.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[]) {

  int tuberia1[2];
  int tuberia2[2];
  char mensaje[] = "Esto es un mensaje con                ";
  int i = 0;

  if (pipe(tuberia1) < 0) {
    perror("Error openning pipe");
    exit(1);
  }
  
  if (pipe(tuberia2) < 0) {
    perror("Error openning pipe");
    exit(1);
  }

  if (fork() == 0) { /* Hijo */

    close(0);
    dup2(tuberia1[0], 0);
    close(1);
    dup2(tuberia2[1], 1);
    close(tuberia1[0]);
    close(tuberia1[1]);
    close(tuberia2[0]);
    close(tuberia2[1]);
    
    execl("./prueba2", "prueba2", NULL);
    fprintf(stderr, "Error ejecutando prueba2\n");
    exit(1);
  }
  
  close(0);
  dup2(tuberia2[0], 0);
  close(1);
  dup2(tuberia1[1], 1);
  close(tuberia1[0]);
  close(tuberia1[1]);
  close(tuberia2[0]);
  close(tuberia2[1]);    

  for (;;) {
    int length = sizeof(mensaje);

    sprintf(mensaje + (length - 15), "%3d", i);
    write(1, mensaje, length);
    read(0, mensaje, length);
    i++;
    fprintf(stderr, "%s\n", mensaje);
  }
}
