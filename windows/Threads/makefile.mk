all: CreateThread

CreateThread: CreateThread.o
	$(CC) -o $@ $^

CreateThread.o: CreateThread.c

clean:
	rm -f CreateThread
	rm -f CreateThread.o
