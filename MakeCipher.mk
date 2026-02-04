
all: cipher

cipher: cipher.o
	gcc -o $@ $< -lcrypt

cipher.o: cipher.c
	gcc -c $<
