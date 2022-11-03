all: clone

clone: main.o args.o common.o clone.o
	gcc -o $@ $^ -lgit2

args.o: args.c args.h
	gcc -c $<

common.o: common.c common.h args.h
	gcc -c $<

clone.o: clone.c common.h
	gcc -c $< 

clean:
	rm -f *.o
	rm -f clone
