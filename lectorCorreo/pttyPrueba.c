#include <stdio.h>
#include "ptty_utils.h"

int
main(int argc, char *argv[]) {

  char pty_name[80];
  int pty_masterfd;

  pty_masterfd = ptym_open(pty_name);

  printf("descriptor: %d nombre: %s\n", pty_masterfd, pty_name);
  
  close(pty_masterfd);
}
