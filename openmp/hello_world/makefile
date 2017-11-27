
all: hello_world_openmp

LDFLAGS=-fopenmp

hello_world_openmp: hello_world_openmp.o

hello_world_openmp.o: hello_world_openmp.c

clean:
	rm -f *.o
	rm -f hello_world_openmp
	rm -f *.*~ *~
