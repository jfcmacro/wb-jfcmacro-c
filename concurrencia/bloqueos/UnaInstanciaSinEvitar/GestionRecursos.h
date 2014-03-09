#ifndef _GESTIONRECURSOS_H
#define _GESTIONRECURSOS_H

struct Recurso;

typedef struct Recursos {int semid; int semkey;} Recurso;
typedef Recurso *PRecurso;

PRecurso crearRecurso();
void solicitarRecurso(PRecurso recurso);
void liberarRecurso(PRecurso recurso);
void destruirRecurso(PRecurso recurso);

#endif
