// hernán darío toro e.
#include <iostream.h>
#include <conio.h>

struct Elem{
int info;
//int exp;
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
void insListaSimple(Tipo);
void anxListaSimple(Tipo);
void elimListaSimple();
void antListaSimple();
void primListaSimple(){ventana = cabeza -> sig;}
void sigListaSimple(){ventana = ventana -> sig;}
// Funciones analizadoras
bool finListaSimple();
int longListaSimple(){return longitud;}
bool vaciaListaSimple();
Tipo infoListaSimple(){return ventana -> info;}
// Funcióon destructora
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
// y sitúa la ventana en el nodo siguiente
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

// Destruye cada uno de los nodos de la lista
template <class Tipo>
ListaSimple<Tipo> :: ~ListaSimple()
{
primListaSimple();
while(!finListaSimple()){
cout << "\nEliminando...";
elimListaSimple();
}
getch();
}

// Módulo principal
/*void main()
{
ListaSimple<Elem> l;
Elem e;
strcpy(e.codigo,"123");
e.nota = 4.5;
l.insListaSimple(e);
strcpy(e.codigo,"345");
e.nota = 2.4;
l.insListaSimple(e);
strcpy(e.codigo,"567");
e.nota = 7.3;
l.insListaSimple(e);
strcpy(e.codigo,"789");
e.nota = 1.8;
l.insListaSimple(e);
l.primListaSimple();
while(!l.finListaSimple()){
cout << l.infoListaSimple().codigo << " ";
cout << l.infoListaSimple().nota << endl;
l.sigListaSimple();
}
cout << l.longListaSimple();
getch(); */
