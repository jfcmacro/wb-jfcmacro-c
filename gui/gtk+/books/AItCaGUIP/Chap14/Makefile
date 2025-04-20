.phony: clean

all: main

main: main.o
	$(CC) -o $@ `pkg-config --libs gtk+-3.0` $<

main.o: main.c
	$(CC) -c $< `pkg-config --cflags gtk+-3.0`

clean:
	rm -f main
	rm -f *.o
	rm -f *.*~ *~ 
