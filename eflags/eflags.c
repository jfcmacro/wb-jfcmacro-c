#include <stdio.h>
#include <stdlib.h>

#define MASCARA_C 0x00000001
#define MASCARA_P 0x00000004
#define MASCARA_A 0x00000010
#define MASCARA_Z 0x00000040
#define MASCARA_S 0x00000080
#define MASCARA_T 0x00000100
#define MASCARA_I 0x00000200
#define MASCARA_D 0x00000400
#define MASCARA_O 0x00000800

int
main(int argc, char *argv[]) {

  unsigned int valor;
  char salida1[] = "ODITSZAPC";
  char salida2[] = "000000000";

  if (argc != 2) {
    fprintf(stderr, "Uso: %s <numero_hexa>\n", argv[0]);
    exit(1);
  }

  valor = (unsigned int) strtol(argv[1], NULL, 16);

  salida2[0] = ((valor & MASCARA_O) != 0) ? '1' : '0';
  salida2[1] = ((valor & MASCARA_D) != 0) ? '1' : '0';
  salida2[2] = ((valor & MASCARA_I) != 0) ? '1' : '0';
  salida2[3] = ((valor & MASCARA_T) != 0) ? '1' : '0';
  salida2[4] = ((valor & MASCARA_S) != 0) ? '1' : '0';
  salida2[5] = ((valor & MASCARA_Z) != 0) ? '1' : '0';
  salida2[6] = ((valor & MASCARA_A) != 0) ? '1' : '0'; 
  salida2[7] = ((valor & MASCARA_P) != 0) ? '1' : '0';
  salida2[8] = ((valor & MASCARA_C) != 0) ? '1' : '0';

  fprintf(stdout, "%s\n", salida1);
  fprintf(stdout, "%s\n", salida2);
  
  exit(0);
}
