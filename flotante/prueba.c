#include <stdio.h>

int
main(int argc, char *argv) {

  int i[] = {0xf0100010, 0x7f805354, 0x01123ab9, 
	     0xff803033, 0xff013433, 0x7f803033};
  float *f;
  int j;

  f = (float *) &i;

  for (j = 0; j < (sizeof(i)/sizeof(int)); j++) {
    fprintf(stdout, "%g\n", *(f + j));
  }

  return 0;

}
