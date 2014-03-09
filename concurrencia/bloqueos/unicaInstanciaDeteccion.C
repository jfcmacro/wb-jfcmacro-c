#include <iostream>

struct Point {
  int x;
  int y;
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  Point() {
    this->x = 0;
    this->y = 0;
  }
};

struct Arreglo {
  int **arreglo;
  int length;
  int height;

  Arreglo(int length, int height) {
    this->length = length;
    this->height = height;

    arreglo = new int*[height];
    for (int i = 0; i < height; i++) {
      arreglo[i] = new int[length];
    }
  }
  ~Arreglo() {
    for (int i = 0; i < height; i++) {
      delete[] arreglo[i];
    }
    delete[] arreglo;
  }
  Point
  buscarHorizontal(Point origen) { 
    int i;
    int j = origen.x;

    for (i = 0; i < length; i++) {
      if (i == origen.y) 
	continue;
      if (arreglo[i][j] != ' ')
	return Point(i, j);
    }
    return Point(-1, -1);
  }

  Point
  buscarVertical(Point origen) {
    int i = origen.y;
    int j;

    for (j = 0; i < height; i++) {
      if (j = origen.x) 
	continue;
      if (arreglo[i][j] != ' ')
	return Point(i, j);
    }
    
    return Point(-1, -1);
  }

  bool
  esCircular(Arreglo arreglo, Point origen) {

    return true;
  }
};




int
main(int argc, char *argv[]) {

  return 0;
}
