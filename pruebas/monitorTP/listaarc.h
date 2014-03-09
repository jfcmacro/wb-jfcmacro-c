// Manipulación de listas
#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>



struct Elem{
	char nombre[15];
	int edad;
	float est;
	int peso;

};

struct Nodo{
	Elem info;
	Nodo *sig;
};

// Declaración de una clase genérica ListaSimple
template <class Tipo>
class ListaSimple{
	Nodo *cabeza, *ventana;
   	int longitud;
public:
	// Función constructora
	ListaSimple();
   	// Funciones modificadoras
   	int cargarListaSimple(char *);
   	void insListaSimple(Tipo);
   	void anxListaSimple(Tipo);
   	void elimListaSimple();
   	void antListaSimple();
   	void primListaSimple(){ventana = cabeza -> sig;}
	void sigListaSimple(){ventana = ventana -> sig;}
	void escribaListaSimple();
  	// Funciones analizadoras
   	int salvarListaSimple(char *);
   	bool finListaSimple();
   	int longListaSimple(){return longitud;}
   	bool vaciaListaSimple();
   	Tipo infoListaSimple(){return ventana -> info;}
   	// Función destructora
   	~ListaSimple();
};

// Función constructora
// Crea nodo encabezador e inicializa longitud en 0
template <class Tipo>
ListaSimple<Tipo> :: ListaSimple()
{
	cabeza = new Nodo;
	cabeza -> sig = NULL;
   	ventana = cabeza;
   	longitud = 0;
}

// Carga una lista desde un archivo
template <class Tipo>
int ListaSimple<Tipo> :: cargarListaSimple(char*nombre)
{
   	ifstream archEntrada(nombre, ios::in | ios::binary);
	if(!archEntrada){
cerr << "Error: no fue posible abrir el archivo " << endl;
      		return 1;
   	}
   	Tipo x;
   	archEntrada.read((unsigned char*) &x, sizeof x);
   	while(!archEntrada.eof()){
      		anxListaSimple(x);
      		archEntrada.read((unsigned char*) &x, sizeof x);
   	}
   	archEntrada.close();
	return 0;
}

// Adiciona un nuevo nodo después de la ventana
// y sitúa la ventana en el nuevo nodo
template <class Tipo>
void ListaSimple<Tipo> :: anxListaSimple(Tipo x)
{
	Nodo *pt;
   	pt = new Nodo;
   	pt -> info = x;
   	pt -> sig = ventana -> sig;
   	ventana -> sig = pt;
   	ventana = pt;
   	longitud++;
}
// Adiciona un nuevo nodo antes de la ventana
// y sitúa la ventana en el nuevo nodo
template <class Tipo>
void ListaSimple<Tipo> :: insListaSimple(Tipo x)
{
	Nodo *pt;
   	pt = new Nodo;
   	pt -> info = x;
   	if(vaciaListaSimple()){
      		cabeza -> sig = pt;
      		pt -> sig = NULL;
  	 }else{
      		pt -> sig = ventana;
      		antListaSimple();
      		ventana -> sig = pt;
   	}
   	ventana = pt;
   	longitud++;
}

// Sitúa la ventana en el nodo anterior
template <class Tipo>
void ListaSimple<Tipo> :: antListaSimple()
{
	Nodo *pt;
   	pt = cabeza;
   	if(!vaciaListaSimple()){
      	while(pt -> sig != ventana)
         		pt = pt -> sig;
      	ventana = pt;
   	}
}

// Elimina el nodo de la ventana
// La ventana se sitúa en el nodo siguiente
// Pre: la ventana está definida
template <class Tipo>
void ListaSimple<Tipo> :: elimListaSimple()
{
	Nodo *pt;
   	pt = ventana;
   	antListaSimple();
   	ventana -> sig = pt -> sig;
   	ventana = ventana -> sig;
   	delete pt;
   	longitud--;
}
template <class Tipo>
void ListaSimple<Tipo> :: escribaListaSimple()
{
  Elem x;
  for(primListaSimple(); !finListaSimple(); sigListaSimple()){
     x=infoListaSimple();
     cout<<x.nombre<<"  "<<x.edad<<endl;
  }
}

// Informa si no existen más nodos, es decir,
// si se ha llegado al final de la lista 
template <class Tipo>
bool ListaSimple<Tipo> :: finListaSimple()
{
	bool ind = false;
   	if(ventana == NULL)
      		ind = true;
   	return ind;
}

// Informa si la lista está vacía
template <class Tipo>
bool ListaSimple<Tipo> :: vaciaListaSimple()
{
	bool ind = false;
   	if(cabeza -> sig == NULL)
      		ind = true;
   	return ind;
}

// Guarda la informacion de la lista en un archivo
template <class Tipo>
int ListaSimple<Tipo> :: salvarListaSimple(char*nombre)
{
   	ofstream archSalida(nombre, ios::out | ios :: binary);
   	if(!archSalida){
      		cerr << "Error: no se pudo abrir el archivo " << endl;
      		return 1;
   	}
   	Tipo x;
   	primListaSimple();
   	while(!finListaSimple()){
      		x = infoListaSimple();
      		archSalida.write((unsigned char*) &x, sizeof x);
      		cout <<  "\nGrabando y eliminando...";
      		elimListaSimple();
   	}
   	archSalida.close();
   	return 0;
}

// Destruye cada uno de los nodos de la lista
template <class Tipo>
ListaSimple<Tipo> :: ~ListaSimple()
{
	primListaSimple();
   	while(!finListaSimple()){
      		cout <<  "\nEliminando...";
      		elimListaSimple();
   	}
   	getch();
}
//carga la lista de un archivo
template<class Tipo>
int ListaSimple<Tipo>::cargarListaSimple(char *nombre)
{
	ifstream archEntrada(nombre, ios::in | ios::binary);
	if(!archEntrada)
	{
		cerr << "Error no fue posible abrir el archivo" << endl;
		return 1;
	}
	Tipo x;
	archEntrada.read((unsigned char*)&x, sizeof x);
	while (!archEntrada.eof())
	{
		anxListaSimple(x);
                archEntrada.read((unsigned char*)&x,sizeof x);
	}
	archEntrada.close();
	return 0;
}

// Guardar la informacion de la lista en un archivo
template<class Tipo>
int ListaSimple<Tipo>::salvarListaSimple(char *nombre)
{
	ofstream archSalida(nombre, ios:: out | ios :: binary);
	if (!archSalida)
	{
		cerr << "Error: no se pudo abrir el archivo" << endl;
		return 1;
	}
	Tipo x;
	primListaSimple();
	while (!finListaSimple())
	{
		x=infoListaSimple();
		archSalida.write((unsigned char*)&x, sizeof x);
		cout << "\n Eliminando...";
		elimListaSimple();
	}
	archSalida.close();
	return 0;
}


