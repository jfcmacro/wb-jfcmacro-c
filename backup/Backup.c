#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "backup.h"

void
usageEnd(char *progname) {
  fprintf(stderr, "Uso: %s archivo1 [archivo2]\n", progname);
  ExitProcess((DWORD) 0);
}

BOOL
hacerBackup(char* filename, HANDLE hBackupDis, int ultimo) {
  HANDLE hArchivo;
  Encabezado encabezado;
  Datos      buffer;
  DWORD      nCarLeidos;
  BOOL       noFinDeArchivo = TRUE;
  DWORD      nCarEscritos;
  BY_HANDLE_FILE_INFORMATION bhfiBuffer;
  
  hArchivo = CreateFile(filename, GENERIC_READ,
			FILE_SHARE_READ | FILE_SHARE_WRITE, 
			NULL, OPEN_EXISTING, 0, NULL);

  if (hArchivo == INVALID_HANDLE_VALUE) {
    fprintf(stderr, "No se pudo abrir el archivo debido a %ld\n", 
	    GetLastError());
    return FALSE;
  }

  if (!GetFileInformationByHandle(hArchivo, &bhfiBuffer)) {
    fprintf(stderr, "No se pudo obtener la informacion del archivo %ld\n",
	    GetLastError());
    CloseHandle(hArchivo);
    return FALSE;
  }

  ZeroMemory(&encabezado, BLOCKSIZE);
  strcpy(encabezado.nombre, filename);
  encabezado.tamanoBytes = bhfiBuffer.nFileSizeLow;
  encabezado.tamanoBloques = bhfiBuffer.nFileSizeLow / BLOCKSIZE;
  encabezado.ultimo = ultimo;

  fprintf(stdout, "Es ultimo: %s\n", ultimo ? "yes" : "no");

  WriteFile(hBackupDis, &encabezado, BLOCKSIZE, &nCarEscritos, NULL);

  // Se supone que si hay mas de un archivo cabe en el diskette
  
  while (noFinDeArchivo) {
    
    ZeroMemory(&buffer, BLOCKSIZE);
    ReadFile(hArchivo, buffer.datos, BLOCKSIZE, &nCarLeidos, NULL);
    
    if (nCarLeidos == 0)
      noFinDeArchivo = FALSE;
    else {
      WriteFile(hBackupDis, buffer.datos, BLOCKSIZE, &nCarEscritos, NULL);
    }
  }

  CloseHandle(hArchivo);
  return TRUE;
}

int
main(int argc, char *argv[]) {

  Encabezado datos;
  Datos      buffer;
  HANDLE     hDiskette;
  int	     totalArchivos;
  char*      archivo1 = NULL;
  char*      archivo2 = NULL;

  switch (argc) {
  case 1:
    usageEnd(argv[0]);
    break;
  case 2:
	totalArchivos = 1;
    archivo1 = argv[1];
    break;
  case 3:
    totalArchivos = 2;
    archivo1 = argv[1];
    archivo2 = argv[2];
    break;
  default:
    usageEnd(argv[0]);
    break;
  };

  hDiskette = CreateFile("\\\\.\\A:",GENERIC_WRITE, 
                         FILE_SHARE_WRITE | FILE_SHARE_READ, NULL,
                         OPEN_EXISTING, 0, NULL);
  
  if (hDiskette == INVALID_HANDLE_VALUE) {
    fprintf(stderr, "Error al tratar de abrir el archivo %ld\r\n",
	    GetLastError());
    ExitProcess(0);
  }

  fprintf(stdout, "Total de archivos: %d\n", totalArchivos);

  hacerBackup(archivo1, hDiskette, (--totalArchivos > 0) ? 0 : 1);
  
  if (archivo2)
	  hacerBackup(archivo2, hDiskette, (--totalArchivos > 0) ? 0 : 1);

  CloseHandle(hDiskette);

  ExitProcess((DWORD) 0);
  
}
