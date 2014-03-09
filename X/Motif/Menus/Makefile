RM = rm -f
CC = gcc
CFLAGS = -O -g
INCLUDES = -I/usr/X11R6/include/ -I/usr/include/X11
LIBS = -L/usr/X11R6/lib -lXm -lXt 

.c.o:
	$(RM) $@
	$(CC) -c $(CFLAGS) $(INCLUDES) $<

all: Menu XExample5

Menu:	Menu.o
	$(RM) $@
	$(CC) -o $@ $(CFLAGS) $< $(LIBS)
	@echo Terminada la ejecucion del archivo de construcción

XExample5: XExample5.o
	$(RM) $@
	$(CC) -o $@ $(CFLAGS) $< $(LIBS)
	@echo Terminada la ejecucion del archivo de construcción


