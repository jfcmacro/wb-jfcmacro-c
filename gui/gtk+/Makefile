
all: prueba HelloWorld

GTK_CFLAGS=`pkg-config --cflags gtk+-2.0`
GTK_LDFLAGS=`pkg-config --libs  gtk+-2.0`

CFLAGS=-g -Wall
LDFLAGS="-lpthread"

HelloWorld: HelloWorld.o
	${CC} -o $@ $< ${LDFLAGS} ${GTK_LDFLAGS}

HelloWorld.o: HelloWorld.c
	${CC} ${CFLAGS} ${GTK_CFLAGS} -c $<

prueba: prueba.o
	${CC} -o $@ $< ${LDFLAGS} ${GTK_LDFLAGS}

prueba.o: prueba.c
	${CC} ${CFLAGS} ${GTK_CFLAGS} -c $< 

clean:
	rm -f *.o *.*~ *~
	rm -f prueba HelloWorld
