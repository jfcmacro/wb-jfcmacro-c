#include <stdio.h>
#include <stdlib.h>
#include <git2.h>
#include "clone.h"

int
main(int argc, char* argv[]) {
  git_libgit2_init();
  int error;
  git_repository *repo = NULL;
  /* if ((error = lg2_clone(NULL, argc, argv)) < GIT_OK) { */
  if ((error = lg2_simple_clone(&repo, argv[1], argv[2])) < GIT_OK) {
    const git_error *e = git_error_last();
    printf("Error %d/%d: %s\n", error, e->klass, e->message);
    return EXIT_FAILURE;
  }
  git_libgit2_shutdown();
  return EXIT_SUCCESS;
}
