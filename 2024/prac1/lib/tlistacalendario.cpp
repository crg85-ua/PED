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

    if (this->pos->siguiente != NULL)
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
    this->primero = NULL;
    *this = lista;   

}

TListaCalendario::~TListaCalendario() {
    TNodoCalendario *nodo = this->primero;

    while (this->primero)
    {
        this->primero = nodo->siguiente;
        delete nodo;
        nodo = this->primero;
    }
    
    this->primero = NULL;
}

TListaCalendario &TListaCalendario::operator=(const TListaCalendario &listaCalendario) {
     if (this != &listaCalendario) {
        // Delete current list
        TNodoCalendario *nodo = this->primero;
        while (nodo) {
            TNodoCalendario *nodoToDelete = nodo;
            nodo = nodo->siguiente;
            delete nodoToDelete;
        }

        // Copy new list
        TNodoCalendario *nodoCopy = listaCalendario.primero;
        TNodoCalendario *lastNode = NULL;
        while (nodoCopy) {
            TNodoCalendario *newNode = new TNodoCalendario();
            newNode->c = nodoCopy->c;

            if (lastNode == NULL) {
                this->primero = newNode;
            } else {
                lastNode->siguiente = newNode;
            }

            lastNode = newNode;
            nodoCopy = nodoCopy->siguiente;
        }
    }

    return *this;
}

bool TListaCalendario::operator==(const TListaCalendario &listaCalendario) {
    bool igual = false;
    TNodoCalendario *lista1 = this->primero;
    TNodoCalendario *lista2 = listaCalendario.primero;    

    while (lista1 && lista2 && lista1->c == lista2->c)
    {
        lista1 = lista1->siguiente;
        lista2 = lista2->siguiente;
    }

    if (lista1 == NULL && lista2 == NULL)
    {
        igual = true;
    }

    return igual;
}

TListaCalendario TListaCalendario::operator+( const TListaCalendario &listaCalendario) const {
    TListaCalendario lista = *this;
    TNodoCalendario *nodo = listaCalendario.primero;

    while (nodo)
    {
        lista.Insertar(nodo->c);
        nodo = nodo->siguiente;
    }
    
    return lista;
}

TListaCalendario TListaCalendario::operator-(const TListaCalendario &listaCalendario) const {
    TListaCalendario lista = *this;
    TNodoCalendario *nodo = listaCalendario.primero;

    while (nodo)
    {
        lista.Borrar(nodo->c);
        nodo = nodo->siguiente;
    }
    
    return lista;
}

bool TListaCalendario::Insertar(const TCalendario &calendario) {
   // Create new node
TNodoCalendario *newNode = new TNodoCalendario();
newNode->c = calendario;

// If list is empty or new node should be inserted at the beginning
if (this->EsVacia() || calendario < this->primero->c)
{
    newNode->siguiente = this->primero;
    this->primero = newNode;
}
else
{
    // Find the node before the insertion point
    TNodoCalendario *current = this->primero;
    while (current->siguiente != NULL && current->siguiente->c < calendario)
    {
        current = current->siguiente;
    }

    // Insert new node
    newNode->siguiente = current->siguiente;
    current->siguiente = newNode;
}

return true;
}

bool TListaCalendario::Borrar( TCalendario &calendario) {
    TNodoCalendario *nodo = this->primero;
    TNodoCalendario *nodoAnterior = NULL;
    bool encontrado = false;

    while (nodo)
    {
        if (nodo->c == calendario)
        {
            encontrado = true;
            TNodoCalendario *nodoToDelete = nodo;
            nodo = nodo->siguiente;

            if (nodoToDelete == this->primero)
            {
                this->primero = nodo;
            }
            else
            {
                nodoAnterior->siguiente = nodo;
            }

            delete nodoToDelete;
        }
        else
        {
            nodoAnterior = nodo;
            nodo = nodo->siguiente;
        }
    }

    return encontrado;
}

bool TListaCalendario::Borrar( TListaPos &listaPos) {
    bool encontrado;
    TNodoCalendario *ptl, *pta;
    ptl = primero;
    encontrado = false;
    pta = NULL;

    while (ptl && encontrado)
    {
        if (ptl == listaPos.pos)
        {
            encontrado = true;
        }
        else
        {
            pta = ptl;
            ptl = ptl->siguiente;
        }
    }

    if (encontrado)
    {
        if (ptl == primero){

            primero = primero->siguiente;
        }else{
            pta->siguiente = ptl->siguiente;
        }

        listaPos.pos = NULL;
    }

    return encontrado;
}

bool TListaCalendario::Borrar(int dia, int mes, int anyo) {

    TNodoCalendario *nodo = this->primero;
    TNodoCalendario *nodoAnterior = NULL;
    bool encontrado = false;

    while (nodo)
    {
        if (nodo->c.Anyo() < anyo || (nodo->c.Anyo() == anyo && nodo->c.Mes() < mes) 
        || (nodo->c.Anyo() == anyo && nodo->c.Mes() == mes && nodo->c.Dia() < dia))
        {
            encontrado = true;
            TNodoCalendario *nodoToDelete = nodo;
            nodo = nodo->siguiente;

            if (nodoToDelete == this->primero)
            {
                this->primero = nodo;
            }
            else
            {
                nodoAnterior->siguiente = nodo;
            }

            delete nodoToDelete;
        }
        else
        {
            nodoAnterior = nodo;
            nodo = nodo->siguiente;
        }
    }

    return encontrado;
}



bool TListaCalendario::EsVacia() const {
    return primero == NULL;
}

TCalendario TListaCalendario::Obtener(const TListaPos &listaPos) const {
    bool encontrado = false;
    TNodoCalendario *nodo = this->primero;
    while (nodo && !encontrado)
    {
        if (nodo == listaPos.pos)
        {
            encontrado = true;
        }else{
            nodo = nodo->siguiente;
        }
    }

    return nodo->c;
}

bool TListaCalendario::Buscar(const TCalendario &calendario) const {
    TNodoCalendario *nodo = this->primero;
    bool encontrado = false;

    while (nodo && !encontrado)
    {
        if (nodo->c == calendario)
        {
            encontrado = true;
        }else{
            nodo = nodo->siguiente;
        }
    }

    return encontrado;
}

int TListaCalendario::Longitud() const {
    TNodoCalendario *nodo = this->primero;
    int cantidad = 0;

    while (nodo)
    {
        cantidad++;
        nodo = nodo->siguiente;
    }

    return cantidad;
}

TListaPos TListaCalendario::Primera() const {
    TListaPos listaPos;
    listaPos.pos = this->primero;
    return listaPos;
}

TListaPos TListaCalendario::Ultima() const {
    TListaPos listaPos;
    TNodoCalendario *nodo = this->primero;

    while (nodo && nodo->siguiente)
    {
        nodo = nodo->siguiente;
    }

    listaPos.pos = nodo;
    return listaPos;
}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2) const{
    TListaCalendario lista1 = *this;
    TListaCalendario lista2 = L2;
    TListaCalendario listaSuma;

    listaSuma = lista1.ExtraerRango(I_L1, F_L1) + lista2.ExtraerRango(I_L2, F_L2);

    return listaSuma;
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
    
    
    return ordenadas;
}

// //Sobrecarga del operador salida
ostream& operator<<(ostream& os, const TListaCalendario& listaCalendario) {
    TNodoCalendario *nodo;
    nodo = listaCalendario.primero;
    os << "<";
    while (nodo)
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