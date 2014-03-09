RM = rm -f
CC = gcc
CFLAGS = -O
LDFLAGS = -L/usr/X11R6/lib
INCLUDES = -I. -I/usr/include -I/usr/include/X11/ -I/usr/X11R6/include/
LIBS = -lXm -lXt -lX11 

.c.o:
	$(RM) $@
	$(CC) -c $(CFLAGS) $(INCLUDES) $<

all: Teclado PruebaMotif prueba draw draw_input

Teclado: Teclado.o
	$(RM) $@
	$(CC) -o $@ $(CFLAGS) Teclado.o $(LDFLAGS) $(LIBS) 
	@echo Terminada la ejecucion del archivo de construccion del Teclado

PruebaMotif: PruebaMotif.o
	$(RM) $@
	$(CC) -o $@ $(CFLAGS) PruebaMotif.o $(LDFLAGS) $(LIBS)
	@echo Terminada la ejecucion del archivo de construccion de PreubaMotif

draw: draw.o
	$(RM) $@
	$(CC) -o $@ $(CFLAGS) draw.o $(LDFLAGS) $(LIBS)
	@echo Terminada la ejecución del archivo de construción de draw

draw_input: draw_input.o
	$(RM) $@
	$(CC) -o $@ $(CFLAGS) draw_input.o $(LDFLAGS) $(LIBS)
	@echo Terminada la ejecución del archivo de construción de draw_input

prueba: prueba.o
	$(RM) $@
	$(CC) -o $@ $(CFLAGS) prueba.o $(LDFLAGS) $(LIBS)
	@echo Terminada la ejecución del archivo de construción de prueba