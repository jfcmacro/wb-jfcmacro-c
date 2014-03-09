#ifndef UTILITIES_H
#define UTILITIES_H
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int mksocket(const char*);
int mksocketclient();
int mkconnect(int s, const char *);
void usage(const char*);
int validarError(fd_set*, int);
int leerEscribir(fd_set*, int, int);

#endif
