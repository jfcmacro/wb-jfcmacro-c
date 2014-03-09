#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void
usage(char *progname) {
  fprintf(stderr, "Usage: %s nota1 nota2 nota3 nota4");
  _exit(1);
}

int
main(int argc, char *argv[]) {

  float parcial1, parcial2, parcial3, seguimiento;
  float total;
  float final;

  if (argc != 5) {
    usage(argv[0]);
  }

  sscanf(argv[1], "%f", &parcial1);
  sscanf(argv[2], "%f", &parcial2);
  sscanf(argv[3], "%f", &parcial3);
  sscanf(argv[4], "%f", &seguimiento);

  total = parcial1 * 0.20 + parcial2 * 0.20 + parcial3 * 0.2 + seguimiento * 0.1;

  final = 3.0 - total / 0.7;

  fprintf(stdout, "Parcial 1: %f Parcial 2: %f Parcial 3: %f Seguimiento: %f\n", parcial1, parcial2, parcial3, seguimiento);
  fprintf(stdout, "total: %f final: %f\n", total / 0.7, final / 0.3);
  return 0;
}
