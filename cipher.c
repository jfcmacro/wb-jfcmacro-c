#include <crypt.h>
#include <stdio.h>
#include <unistd.h>

void
usage(const char* progname) {
  fprintf(stderr, "%s: usage <value_to_cipher>\n", progname);
  _exit(1);
}

int
main(int argc, char* argv[]) {
  if (argc != 2) {
    usage(argv[0]);
  }
    
  char *cipher = crypt(argv[1], "xx");

  fprintf(stdout, "%s -> %s\n", argv[1], cipher);
  
  _exit(0);
}
