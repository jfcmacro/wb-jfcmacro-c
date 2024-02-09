all: Cliente Servidor

Cliente: Cliente.o
	g++ -o $@ $^

Servidor: Servidor.o
	g++ -o $@ $^

clean:
	rm -f *.o *.exe
	rm -f *~ *.*~

