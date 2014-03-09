#include <stdio.h>

int
main()
{
  int i;

  for (i = 0; sys_errlist[i]; i++) {

    fprintf(stdout, "sys_errlist[%d]=%s\n", i, sys_errlist[i]);
  }

  return 0;
}
