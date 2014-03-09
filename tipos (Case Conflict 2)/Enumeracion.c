#include <stdio.h>

int
main(int argc, char *argv[]) {

  enum Enumeracion { UNO = 1, DOS = 2, TRES = 3 } e;
  int i;
  
  for (i = 0, e = UNO ; i < 10; i++, e++) {
    
    printf("e: %d\n", e);
  }
   
  return 0;
}
