all: CreateThread

CreateThread: CreateThread.obj
	$(CC) /Fe: CreateThread CreateThread.obj

CreateThread.obj: CreateThread.c
	$(CC) /c CreateThread.c

clean:
	$(RM) CreateThread.obj CreateThread.exe
