.SUFFIXES: .c .s .o

.c.s : # Regla
	${CC} -S $<

.s.o : # Regla1x
	${AS} -o ${@} $<

fuentes= getbits.c rgetbits.c main.c
objetos= ${fuentes:.c=.o}
assembler= ${fuentes.c=.s}

all: main

main: ${objetos}
#	@echo "Objetos: ${objetos}"
#	@echo "Fuentes: ${fuentes}"
#	gcc -o $@ ${objetos}
