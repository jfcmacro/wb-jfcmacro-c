RM = rm -f
CC = gcc
CFLAGS = -O
INCLUDES = -I/usr/X11R6/include/ -I/usr/include/X11
LIBS = -L/usr/X11R6/lib -lXm -lXt 

.c.o:
	$(RM) $@
	$(CC) -c $(CFLAGS) $(INCLUDES) $<

all: HolaMundo hello rmtest

HolaMundo:	HolaMundo.o
	$(RM) $@
	$(CC) -o $@ $(CFLAGS) $< $(LIBS)
	@echo Terminada la ejecucion del archivo de construcción

hello:	hello.o
	$(RM) $@
	$(CC) -o $@ $(CFLAGS) $< $(LIBS)

rmtest: rmtest.o
	$(RM) $@
	$(CC) -o $@ $(CFLAGS) $< $(LIBS)



