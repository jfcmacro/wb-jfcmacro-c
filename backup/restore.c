#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "backup.h"

int
hacerRestore(int fdBackupDis,
	     const char *nombre, 
	     int nBloques,
	     int nBytes);

int
main(int argc, char *argv[]) {

  int fd;
  Encabezado encabezado;
  int nCarLeidos;
  int unaVezMas = 1;

  if ((fd = open("/dev/fd0", O_RDONLY)) < 0) {
    fprintf(stderr, "No se pudo abrir dispositivo de backup %d\n",
	    errno);
    exit(1);
  }

  if ((nCarLeidos = read(fd, &encabezado, BLOCKSIZE)) < 0) {
    fprintf(stderr, "No se pudo leer del archivo de encabezado",
	    errno);
    exit(1);
  } 

  do {
    if (hacerRestore(fd, encabezado.nombre, encabezado.tamanoBloques,
		     encabezado.tamanoBytes) < 0) {
      fprintf(stderr, "Error al leer los datos el archivo %s\n",
	      encabezado.nombre);
      exit(1);
    }

    if (encabezado.ultimo) {
      unaVezMas = 0;
    }
    else {
      if ((nCarLeidos = read(fd, &encabezado, BLOCKSIZE)) < 0) {
	fprintf(stderr, "No se pudo leer del archivo de encabezado",
		errno);
      exit(1);
      } 
    }
  } while (unaVezMas);
  
  exit(0);
}

int
hacerRestore(int fd, const char* nombre,
	     int nBloques, int nBytes) {

  Datos buffer;
  int nCarLeidos;
  int outFd;

  if ((outFd = creat(nombre, 0664)) < 0) {
    return -1;
  }

  while (nBloques >= 0) {
    if ((nCarLeidos = read(fd, &buffer, BLOCKSIZE)) < 0)
      return -1;

    if (nBytes >= BLOCKSIZE) 
      write(outFd, &buffer, BLOCKSIZE);
    else
      write(outFd, &buffer, nBytes);

    nBytes -= BLOCKSIZE;
    nBloques--;
  }

}


