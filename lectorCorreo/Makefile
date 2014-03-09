CFLAGS=-g

all: lectorCorreo simuladorSendMail pttyPrueba

simuladorSendMail: simuladorSendMail.o utilidades.o
	gcc -o $@ ${CFLAGS} ${LDFLAGS} simuladorSendMail.o utilidades.o

simuladorSendMail.o: simuladorSendMail.c utilidades.h debug.h

pttyPrueba: pttyPrueba.o ptty_utils.o
	gcc -o $@ ${LDFLAGS} pttyPrueba.o ptty_utils.o

