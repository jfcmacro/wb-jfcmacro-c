CFLAGS= -g

all: cliente servidor

cliente: cliente.o mksocket.o mkconnect.o leerEscribir.o usage.o
	gcc -o cliente cliente.o mksocket.o mkconnect.o leerEscribir.o usage.o

servidor: servidor.o mksocket.o mkconnect.o leerEscribir.o usage.o
	gcc -o servidor servidor.o mksocket.o mkconnect.o leerEscribir.o usage.o