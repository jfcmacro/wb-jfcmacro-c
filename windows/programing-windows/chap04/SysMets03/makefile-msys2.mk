all: SysMets3

SysMets3: SysMets3.o
	${CC} -o $@ $^ /ucrt64/lib/libgdi32.a

SysMets3.o: SysMets3.c SysMets.h
	${CC} -c $<

clean:
	rm -f SysMets3.o SysMets3
	rm -f *~
