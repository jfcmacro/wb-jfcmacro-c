PVM_ROOT=/usr/share/pvm3
PVM_ARCH=LINUXI386
CFLAGS=-I$(PVM_ROOT)/include
CC=gcc
LDFLAGS= -lpvm3 -L$(PVM_ROOT)/lib/$(PVM_ARCH)
BDIR=../bin/${PVM_ARCH}

all: proceso

proceso: proceso.o
	${CC} -o ${@} $< ${LDFLAGS}
	cp ${@} ${BDIR}