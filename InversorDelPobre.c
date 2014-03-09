#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int
residuo(int n) {
  int D = 2;
  int d;

  d = n / D;
  return (n - D*d);

}

int
inversorDelPobre(int n) {

  return residuo(n+1);
}

int
main(int argc, char *argv[]) {

  int n;
  char* pInputBuffer;

  fprintf(stdout, "Entre un digito entre el uno y el cero:\n");
  pInputBuffer = readline("> ");
  sscanf(pInputBuffer, "%d", &n);
  free(pInputBuffer);

  fprintf(stdout, "Inverso: %d\n", inversorDelPobre(n));
  return 0;
}
