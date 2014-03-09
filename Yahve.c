#include <stdio.h>

#define N 4

int
main() {
  // char tetra[] = "YHWH";
  char tetra[] = "gato";

  int i,j,k,l;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
	for (l = 0; l < N; l++) {
	  if (i != j) {
	    if (i != k && j != k) {
	      if ((i != l) && (j != l) && (k != l)) {
		putchar(tetra[i]);
		putchar(tetra[j]);
		putchar(tetra[k]);
		putchar(tetra[l]);
		putchar('\n');
	      }
	    }
	  }
	}
      }
    }
  } 
  return 0;
}
