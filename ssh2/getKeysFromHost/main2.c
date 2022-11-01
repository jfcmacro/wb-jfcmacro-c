#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libssh2.h>

#define SIZE_FILEPATH 256

int
main(int argc, char *argv[]) {
  char filepath[SIZE_FILEPATH];
  LIBSSH2_KNOWNHOSTS* know_hosts;
  explicit_bzero(filepath, SIZE_FILEPATH);
  strcat(strcat(filepath, getenv("HOME")), "/.ssh/known_hosts");
  fprintf(stdout, "File to read %s\n", filepath);
  libssh2_init(0);
  int number_knownhosts = 0;
  if ((number_knownhosts = libssh2_knownhost_readfile(know_hosts,
						      filepath,
						      LIBSSH2_KNOWNHOST_FILE_OPENSSH)) < 0) {
    fprintf(stderr, "Error reading %s\n", filepath);
  }
  else {
    fprintf(stdout, "Number of entries read %s\n", number_knownhosts);
  }
  libssh2_exit();
  return EXIT_SUCCESS;
}
