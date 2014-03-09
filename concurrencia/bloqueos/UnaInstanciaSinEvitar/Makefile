CFLAGS= -g
LDFLAGS=-lpthread

.phony: all clean

all: UnaInstanciaSinEvitar

UnaInstanciaSinEvitar: GestionRecursos.o UnaInstanciaSinEvitar.o
	gcc -o $@ GestionRecursos.o UnaInstanciaSinEvitar.o -lpthread

clean:
	rm *.o UnaInstanciaSinEvitar

