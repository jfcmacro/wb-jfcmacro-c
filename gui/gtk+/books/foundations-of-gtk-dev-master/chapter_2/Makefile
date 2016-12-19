EXES = $(basename $(wildcard *.c))
CC = cc
CFLAGS = -Wall -g `pkg-config --cflags gtk+-2.0`
LDFLAGS = `pkg-config --libs gtk+-2.0`

all: helloworld

helloworld: helloworld.o
	$(CC) $(LDFLAGS) -o $@ $^

helloworld.o: helloworld.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(EXES) *.o
