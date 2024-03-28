#include "tlistacalendario.h"

// Implementación de los métodos de TNodoCalendario

TNodoCalendario::TNodoCalendario(){
    this->siguiente = NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &nodo) {
   this->siguiente = nodo.siguiente;
   this->c = nodo.c;

}

TNodoCalendario::~TNodoCalendario() {
   this->siguiente = NULL;
}

TNodoCalendario &TNodoCalendario::operator=(const TNodoCalendario &nodo) {
   
    this->c = nodo.c;
    this->siguiente = nodo.siguiente;    
    return *this;
}

// Implementación de los métodos de TListaPos

TListaPos::TListaPos(){
    this->pos = NULL;
}

TListaPos::TListaPos(const TListaPos& listaPos) {
    this->pos = listaPos.pos;
}

TListaPos::~TListaPos() {
    this->pos = NULL;
}

TListaPos &TListaPos::operator=(const TListaPos &listaPos) {
    this->pos = listaPos.pos;    
    return *this;
}

bool TListaPos::operator==(const TListaPos &listaPos) {    
    return this->pos == listaPos.pos;
}

bool TListaPos::operator!=(const TListaPos &listaPos) {
    return this->pos != listaPos.pos;
}

TListaPos TListaPos::Siguiente() {
    TListaPos aux;

    if (pos==NULL)
    {
        aux.pos = NULL;
    }else
    {
        aux.pos = this->pos->siguiente;
    }
    
    return aux;
    
}

bool TListaPos::EsVacia() {
    return this->pos == NULL;
}

// Implementación de los métodos de TListaCalendario

TListaCalendario::TListaCalendario(){
    this->primero = NULL;
}

TListaCalendario::TListaCalendario(const TListaCalendario &lista) {
    this->primero = lista.primero;
    *this = lista;
    

}

TListaCalendario::~TListaCalendario() {
    // Aquí debes implementar la lógica para liberar la memoria de los nodos de la lista
}

TListaCalendario &TListaCalendario::operator=(const TListaCalendario &listaCalendario) {
    if (this != &listaCalendario) {
        primero = listaCalendario.primero;
    }
    return *this;
}

bool TListaCalendario::operator==(const TListaCalendario &listaCalendario) {
    return primero == listaCalendario.primero;
}

TListaCalendario& TListaCalendario::operator+(const TListaCalendario &listaCalendario) {
    // Aquí debes implementar la lógica para sumar dos listas de calendario
}

TListaCalendario& TListaCalendario::operator-(const TListaCalendario &listaCalendario) {
    // Aquí debes implementar la lógica para restar dos listas de calendario
}

bool TListaCalendario::Insertar(const TCalendario &calendario) {
    // Aquí debes implementar la lógica para insertar un calendario en la lista
}

bool TListaCalendario::Borrar(const TCalendario &calendario) {
    // Aquí debes implementar la lógica para borrar un calendario de la lista
}

bool TListaCalendario::Borrar(const TListaPos &listaPos) {
    // Aquí debes implementar la lógica para borrar el elemento en la posición indicada de la lista
}

bool TListaCalendario::Borrar(int dia, int mes, int anyo) {
    // Aquí debes implementar la lógica para borrar todos los calendarios con fecha anterior a la pasada
}

bool TListaCalendario::EsVacia() {
    return primero == NULL;
}

TCalendario TListaCalendario::Obtener(const TListaPos &listaPos) {
    // Aquí debes implementar la lógica para obtener el elemento en la posición indicada de la lista
}

bool TListaCalendario::Buscar(const TCalendario &calendario) {
    // Aquí debes implementar la lógica para buscar un calendario en la lista
}

int TListaCalendario::Longitud() {
    // Aquí debes implementar la lógica para obtener la longitud de la lista
}

TListaPos TListaCalendario::Primera() {
}

TListaPos TListaCalendario::Ultima() {
    // Aquí debes implementar la lógica para obtener la última posición en la lista
}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2) {
    // Aquí debes implementar la lógica para sumar dos sublistas en una nueva lista
}

TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2) {
    TListaCalendario ordenadas;
    TCalendario cal;
    TNodoCalendario *nodo = this->primero;
    int contador = 1;

    while (nodo)
    {
        if (contador >= n1 && contador <= n2)
        {
            ordenadas.Insertar(nodo->c);
            cal = nodo->c;
            nodo = nodo->siguiente;
            Borrar(cal);
            contador++;
        }else{
            contador++;
            nodo = nodo->siguiente;
        }
        
    }
    
    
    
}

// //Sobrecarga del operador salida
ostream& operator<<(ostream& os, const TListaCalendario& lista){
    TNodoCalendario *nodo;

    os << "<";
    nodo = lista.primero;
    while (nodo != NULL)
    {
        os << nodo->c;
        nodo = nodo->siguiente;

        if (nodo)
        {
            os << " ";
        }        
    }

    os << ">";

    return os;
    
}