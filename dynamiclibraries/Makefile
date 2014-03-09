
all: loadLibrary holamundo.so

loadLibrary: loadLibrary.o
	gcc -o $@ $< -ldl

holamundo.so: holamundo.o
	gcc -o $@ -shared $<