#include <stdio.h>

const char ms1[] = "Hello World!\n";
const char ms2[] = "Adios mundo!\n";

void f() {
  return;
}

int
main(){

  f();
  printf("%s", ms1);
  printf("%s", ms2);

  return 0;
}
