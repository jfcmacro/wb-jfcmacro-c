CFLAGS=-g -I/usr/share/pvm3/include/
LDFLAGS= -lpvm3 -L/usr/share/pvm3/lib/LINUXI386
PVM_ARCH=LINUXI386 
DIR_DESTINO=../bin/$(PVM_ARCH)

all: main buscarMayor

main: main.o crearMatriz.o log.o
	gcc -o $@ $^ $(LDFLAGS)
	cp $@ $(DIR_DESTINO)

buscarMayor: buscarMayor.o crearMatriz.o log.o
	gcc -o $@ $^ $(LDFLAGS)
	cp $@ $(DIR_DESTINO)

