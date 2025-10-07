all: SysMets2

SysMets2: SysMets2.o
	${CC} -o $@ $^ /ucrt64/lib/libgdi32.a

SysMets2.o: SysMets2.c SysMets.h
	${CC} -c $<

clean:
	rm -f SysMets2.o SysMets2
	rm -f *~
