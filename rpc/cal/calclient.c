#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
#include "cal.h"

int
main(int argc, char* argv[])
{
  CLIENT *cl;
  values par;
  int opt;
  result *res;

  if (argc != 5) {
    fprintf(stderr, "Usage: %s host opt val1 val2", argv[0]);
    exit(1);
  }

  if (!(cl = clnt_create(argv[1],CALPROG, CALVERS, "tcp"))) {
    clnt_pcreateerror(argv[1]);
    exit(1);
  }

  opt = (int) strtol(argv[2], (char **) NULL, 10);
  par.val1 = (int) strtol(argv[3], (char **) NULL, 10);
  par.val2 = (int) strtol(argv[4], (char **) NULL, 10);
  
  switch(opt) {
  case SUM:
    res = sum_1(&par, cl);
    if (res->status == OPER_OK) {
      fprintf(stdout, "La suma de %d y %d es: %d\n", 
	      par.val1, 
	      par.val2,
	      res->result);
    }
    else {
      fprintf(stderr, "Error: en la suma: %d\n", res->code_fail);
    }
    break;
  case SUB:
    break;
  case MUL:
    break;
  case DIV:
    break;
  }
}
