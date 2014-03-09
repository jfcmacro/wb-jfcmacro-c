#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 1024
int
main(int argc, char *argv[], char *argve[])
{
  int i;
  char buffer[MAX_BUFFER + 1];
  
  fprintf(stdout, "Content-type: text/html\r\n");
 
  fprintf(stdout, "<html><head><title>Forma de registro</title></head>\r\n");
  fprintf(stdout, "<body><h1>Formulario de registro</h1>\r\n");

  fprintf(stdout, "
  
  fprintf(stdout, "</body></html>\r\n");
}
