all: MiPrograma libbib.a

libbib.a : libbib.a(a.o) libbib.a(b.o) libbib.a(c.o)
	ranlib libbib.a

MiPrograma: MiPrograma.c libbib.a
	gcc -o $@ MiPrograma.c -L. -lbib

clean: 
	rm -f libbib.a MiPrograma
