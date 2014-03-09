#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 1024
int
main(int argc, char *argv[], char *argve[])
{
  int i;
  char buffer[MAX_BUFFER + 1];
  
  fprintf(stdout, "Content-type: text/html\r\n");
  fprintf(stdout, "Set-cookie: Prueba=test; expires=Friday, 18-May-2002 12:00:00 GMT\r\n\r\n");
  fprintf(stdout, "<html><head><title>Esta es una prueba</title></head>\r\n");
  fprintf(stdout, "<body><h1>Este documento no hace nada</h1>\r\n");
  
  fprintf(stdout, "<h2>Argumentos del programa</h2>\r\n");
  for (i = 0; i < argc; i++) {
    fprintf(stdout, "<p>%s\r\n", argv[i]);
  }
  
  fprintf(stdout, "<h2>Variables de ambiente</h2>\r\n");
  
  for (i = 0; argve[i]; i++) {
    
    fprintf(stdout, "<p>%s\r\n", argve[i]);
  }
  
  fprintf(stdout, "<h2>Entrada estandar</h2>\r\n");

  while (fgets(buffer, MAX_BUFFER + 1, stdin))
    fprintf(stdout, "<p>%s\r\n", buffer);
       
  
  fprintf(stdout, "</body></html>\r\n");
}
