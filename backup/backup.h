#define BLOCKSIZE 512
#define NAMESIZE  256
#define CEROSIZE  244

struct Encabezado {
  char nombre[NAMESIZE];
  int  tamanoBytes;
  int  tamanoBloques;
  int  ultimo;
  char cero[CEROSIZE];
};

struct Datos {
  char datos[BLOCKSIZE];
};

typedef struct Encabezado Encabezado;
typedef struct Datos Datos;
