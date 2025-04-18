LDFLAGS=-lncurses

TARGETS=charattrib changechar attrtest pi acslist acsstring abox chtypestring \
addchstr boxarray boxarray2 unicode ustring

all: $(TARGETS)

unicode: unicode.o
	$(CC) -o $@ $< -lncursesw

ustring: ustring.o
	$(CC) -o $@ $< -lncursesw

clean:
	rm -f $(TARGETS)
	rm -f *.o
	rm -f *.*~ *~

