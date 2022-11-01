all: getKeysFromHost getNumberKnownHosts

LDLIBS=-lssh2
CFLAGS=-g

getKeysFromHost: main.o
	$(CC) -o $@ $^ ${LDLIBS}

getNumberKnownHosts: main2.o
	$(CC) -o $@ $^ ${LDLIBS}

main.o: main.c

main2.o: main2.c

clean:
	rm -f *.o
	rm -f getKeysFromHost getNumberKnownHosts
