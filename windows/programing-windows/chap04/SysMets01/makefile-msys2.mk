all: SysMets1

SysMets1: SysMets1.o
	${CC} -o $@ $^ /ucrt64/lib/libgdi32.a

SysMets1.o: SysMets1.c SysMets.h
	${CC} -c $<

clean:
	rm -f SysMets1.o SysMets1
	rm -f *~
