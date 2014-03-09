CFLAGS=-g -I/usr/share/pvm3/include/
LDFLAGS= -lpvm3 -L/usr/share/pvm3/lib/LINUXI386
PVM_ARCH=LINUXI386 
DIR_DESTINO=../bin/$(PVM_ARCH)

all: startMultMatriz multMatriz

startMultMatriz: startMultMatriz.o crearMatriz.o imprimirMatriz.o
	gcc -o $@ $^ $(LDFLAGS)
	cp $@ $(DIR_DESTINO)

multMatriz: multMatriz.o crearMatriz.o log.o
	gcc -o $@ $^ $(LDFLAGS)
	cp $@ $(DIR_DESTINO)


startMultMatriz.o: startMultMatriz.c datos.h

multMatriz.o: multMatriz.c datos.h
