#ifndef git_clone_h
#define git_clone_h
#include <git2.h>

int lg2_clone(git_repository *repo, int argc, char **argv);
int lg2_simple_clone(git_repository **repo, const char* url, const char *path);

#endif
