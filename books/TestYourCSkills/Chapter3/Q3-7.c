#include <stdio.h>
#include <stdlib.h>

typedef struct respuesta res;
typedef struct respuesta *pres;

struct respuesta {
  int a;
  int b;
  int c;
  int r;
};

/* pres */
/* test1(int a) { */
/*   pres result; */
/*   static int b = 0; */
/*   static int c = 0; */
/*   result = malloc(sizeof(res)); */
/*   result->r = (a <= 20 ? b = 30 : c = 30); */
/*   result->a = a; */
/*   result->b = b; */
/*   result->c = c; */
/*   return result; */
/* } */
 
pres
test2(int a) {
  pres result;
  static int b = 0;
  static int c = 0;
  result = malloc(sizeof(res));
  printfa <= 20 ? (b = 10) : (b = 30);
  result->a = a;
  result->b = b;
  result->c = c;
  return result;
}

int
main() {

  return 0;
}
