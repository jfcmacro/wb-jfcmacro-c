GTK_VERSION="gtk+-2.0" # gtk+-3.0 gtk4
EXES = $(basename $(wildcard *.c))
CC = cc
CFLAGS = -Wall -g `pkg-config --cflags ${GTK_VERSION}`
LDFLAGS = `pkg-config --libs ${GTK_VERSION}`

all: helloworld helloworld2 buttons exercise2-1 exercise2-2

helloworld: helloworld.o
	$(CC) $(LDFLAGS) -o $@ $^

helloworld.o: helloworld.c
	$(CC) $(CFLAGS) -c $<

helloworld2: helloworld2.o
	$(CC) $(LDFLAGS) -o $@ $^

helloworld2.o: helloworld2.c
	$(CC) $(CFLAGS) -c $<

buttons: buttons.o
	$(CC) $(LDFLAGS) -o $@ $^

buttons.o: buttons.c
	$(CC) $(CFLAGS) -c $<

exercise2-1: exercise2-1.o
	$(CC) $(LDFLAGS) -o $@ $^

exercise2-1.o: exercise2-1.c
	$(CC) $(CFLAGS) -c $<

exercise2-2: exercise2-2.o
	$(CC) $(LDFLAGS) -o $@ $^

exercise2-2.o: exercise2-2.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(EXES) *.o *~
