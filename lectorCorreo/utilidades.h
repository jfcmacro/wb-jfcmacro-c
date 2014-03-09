#ifndef _UTILIDADES_H
#define _UTILIDADES_H

FILE* getErrorFile();
void setErrorFileName(char *);

#define GET_ERROR_FILE (FILE *) getErrorFILE()

int createLogFile(char *);
void writeLogFile(char *);

#endif
