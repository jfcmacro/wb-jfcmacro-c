#include <iostream>

struct Point {
  int x;
  int y;
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

struct Arreglo {
  int **arreglo;
  int length;
  int height;

  Arreglo(int length, int height) {
    this->length = lenght;
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

};

Point
buscarHorizontal(Arreglo &arreglo, Point origen) {
  Point retorno;

  return retorno
  
}

Point
buscarVertical(Arreglo &arreglo, Point origen) {
  Point retorno;

  return retorno;
}

bool
esCircular(Arreglo &asignado, Arreglo &solicitud, Point origen) {

  return true;
}

int
main(int argc, char *argv[]) {

}
