#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define N 2

struct archivo{
	char * contenido;
   int lon;
   char * nombre;
};

typedef struct archivo lista;

int guardar_lista (lista * archivos[N], int index){

  int i, tam;
  int file1;

  lista buff;

  file1 = open("/dev/fd0", O_RDWR);

  if (file1 < 0) {
    fprintf(stderr, "Error al abrir el dispositivo: %d %s\n",
	    errno, strerror(errno));
    exit(1);
  }

  for (i = 0; i <= index; i++)
  {
      buff.contenido = archivos[i]->contenido;
      buff.lon = strlen (archivos[i]->contenido) + 1;
      tam = strlen (archivos[i]->nombre) + 1;
	
	fprintf(stderr,"escribe longitud del archivo %d\n", buff.lon);

      write (file1, buff.lon, sizeof(int));

	fprintf(stderr,"escribe el contenido del archivo %s\n", archivos[i]->contenido);

      write (file1, archivos[i]->contenido, buff.lon);

	fprintf(stderr,"escribe longitud del nombre del archivo %d\n", tam);

      write (file1, tam, sizeof(int));

	fprintf(stderr,"escribe nombre del archivo %s\n", archivos[i]->nombre);

      write (file1, archivos[i]->nombre, tam);
    }
//  fclose (file1);

  return 0;
}

lista *leer_lista(lista * archivos[N], int index)
{
  int i, tam;
  int load;
  lista buff;
  char *name;

  load = open("/dev/fd0", O_RDWR);

  if (load < 0) {
    fprintf(stderr, "Error al abrir el dispositivo: %d %s\n",
	    errno, strerror(errno));
    exit(1);
  }

  for (i = 0; i <= index; i++)
    {
      read (load, &(buff.lon), sizeof(int));
      name = malloc (buff.lon);
      read (load, name, buff.lon);
      (index)++;
      archivos[index] = malloc(sizeof(lista));
      archivos[index]->contenido = buff.contenido;
      archivos[index]->lon = buff.lon;

      read (load, tam, sizeof(int));
      archivos[index]->nombre = malloc(sizeof(char)*tam);
      read (load, name, tam);
      strcpy(archivos[index]->nombre,name);
    }
  //fclose (load);
  return 0;

}

char* tomarBuffer(char * archivo) {
  char *buffer;
  FILE * file1 = fopen(archivo,"r");
  int tam = 0;

  fseek(file1,0L,SEEK_END);  
  tam = (int) ftell(file1);
  
  fclose(file1);   	
  
  fprintf(stderr,"tamanio %d\n", tam);

  buffer = malloc(sizeof(char*)*(tam + 1));

  file1 = fopen(archivo,"r");

  fread(buffer, tam, tam, file1);

  fclose(file1);
  
  fprintf(stderr,"archivo contiene: %s\n", buffer);
  return buffer;
}

int main (int argc, char *argv[])
{
  int index = -1;
  lista *dir[N];
  int i;

  for (i = 1; i <= N; i++)
  {
      index++;
      dir[index] = malloc(sizeof(lista));
      dir[index]->contenido = tomarBuffer(argv[i]);
      dir[index]->lon = strlen (dir[index]->contenido) + 1;
      dir[index]->nombre = malloc(sizeof(char)*strlen(argv[i]));
      strcpy(dir[index]->nombre,argv[i]);
	fprintf(stderr,"se guarda %s\n", argv[i]);
  }
	  fprintf(stderr,"se guardara la lista\n");	
  guardar_lista (dir,index);
  return 0;
}

