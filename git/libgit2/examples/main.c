#include <stdio.h>
#include <stdlib.h>
#include <git2.h>
#include "clone.h"

int
main(int argc, char* argv[]) {
  git_libgit2_init();
  lg2_clone(NULL, argc, argv);
  git_libgit2_shutdown();
  return EXIT_SUCCESS;
}
