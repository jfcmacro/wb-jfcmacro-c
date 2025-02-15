all: cpW cpCF

cpW: cpW.o
	$(CC) -o $@ $^

cpCF: cpCF.o
	$(CC) -o $@ $^

cpW.o: cpW.c

cpCF.o: cpCF.c

clean:
	rm -f cpW cpCF
	rm -f cpW.o cpCF.o
	rm -f *~ *.*~
