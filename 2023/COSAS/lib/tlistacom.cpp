#include "tcomplejo.h"
#include "tvectorcom.h"
#include "tlistacom.h"


//TLISTANODO
TListaNodo::TListaNodo() : e(){
    anterior = nullptr;
    siguiente = nullptr;

}

TListaNodo::TListaNodo(TListaNodo& nodo) : e(nodo.e){
    anterior = nodo.anterior;
    siguiente = nodo.siguiente;
}

TListaNodo::~TListaNodo(){
    e.~TComplejo();
    anterior = nullptr;
    siguiente = nullptr;
}

TListaNodo& TListaNodo::operator=(TListaNodo& nodo){
    if (this != &nodo)
    {
        (*this).~TListaNodo();
        this->e = nodo.e;
        this->siguiente = nodo.siguiente;
        this->anterior = nodo.anterior;

    }

    return *this;
}

TComplejo& TListaNodo::GetComplejo(){
    return e;
}
TListaNodo* TListaNodo::GetAnterior(){
    return anterior;
}
TListaNodo* TListaNodo::GetSiguiente(){
    return siguiente;
}


//TLISTAPOS
TListaPos::TListaPos(){
    pos = nullptr;
}

TListaPos::TListaPos(TListaPos& pos){
    this->pos = pos.pos;
}

TListaPos::~TListaPos(){
    pos = nullptr;
}

TListaPos& TListaPos::operator=(const TListaPos& posicion){
    if (this != &posicion)
    {
        this->pos = posicion.pos;        
    }
    return *this;
    
}

bool TListaPos::operator==(const TListaPos& posicion){
    return &pos == &posicion.pos;    
}

bool TListaPos::operator!=(const TListaPos& posicion){
    return &pos != &posicion.pos;
}

TListaPos TListaPos::Anterior() const{
    TListaPos anterior = TListaPos();
    anterior.pos = pos->anterior;
    return anterior;
}

TListaPos TListaPos::Siguiente() const{
    TListaPos siguiente = TListaPos();
    if (pos->siguiente != nullptr)
    {
        siguiente.pos = pos->siguiente;
    }

    return siguiente;
}

bool TListaPos::EsVacia() const{
    return pos == nullptr;
}

//TLISTACOM

TListaCom::TListaCom(){
    primero = nullptr;
    ultimo = nullptr;
}


TListaCom::TListaCom(TListaCom& lista){
    this->primero = lista.primero;
    this->ultimo = lista.ultimo;

}

TListaCom::~TListaCom(){
    TListaNodo *nodo;
    delete ultimo;
    while (primero != nullptr)
    {
        nodo=primero->siguiente;
        delete primero;
        primero = nodo;
    }
}

TListaCom& TListaCom::operator=(TListaCom& lista){
    
    if (this != nullptr){
        this->~TListaCom();

        for(TListaPos i = lista.Ultima(); !i.EsVacia(); i = i.Anterior()){ 
            this->InsCabeza(i.pos->e);
        }        
    }

    return *this;
}

bool TListaCom::operator==(TListaCom& lista){


    while (this->primero != nullptr || this->primero != this->ultimo)
    {
       if (this->primero->e != lista.primero->e)
       {
            return false;
       }
       
       this->primero = this->primero->siguiente;
    }
    
    return true;

}

bool TListaCom::operator!=(TListaCom& lista){

    while (this->primero != nullptr || this->primero != this->ultimo)
    {
    if (this->primero->e != lista.primero->e)
    {
        return true;
    }
    
    this->primero = this->primero->siguiente;
    }
        
    return false;

}

TListaCom TListaCom::operator+(TListaCom& lista){
    
    TListaCom nuevaLista; // Crea una nueva lista vacía

    for(TListaPos i = lista.Ultima(); !i.EsVacia(); i = i.Anterior()){ 
        nuevaLista.InsCabeza(i.pos->e);
    } 

    for(TListaPos i = this->Ultima(); !i.EsVacia(); i = i.Anterior()){ 
        nuevaLista.InsCabeza(i.pos->e);
    } 

    return nuevaLista; // Devuelve la nueva lista       

}

TListaCom TListaCom::operator-(TListaCom& lista){
    TListaCom nuevaLista;
    bool dist;
    for(TListaPos i = this->Ultima(); !i.EsVacia(); i = i.Anterior()){ 
        for(TListaPos j = lista.Ultima(); !j.EsVacia(); i = j.Anterior()){ 
            if (j.pos->e != i.pos->e)
            {
                dist = true;
            }
                        
        }

        if (dist)
        {
            nuevaLista.InsCabeza(i.pos->e);
        }
    } 

    return nuevaLista;

}

bool TListaCom::InsCabeza(TComplejo& nuevo){
    if (this == nullptr) {
       // No se pudo reservar memoria para la lista
        return false;
        
    } else {
        // Si la lista no está vacía, insertar el nuevo nodo al principio
        TListaNodo *nuevoNodo = new TListaNodo();
        nuevoNodo->e = nuevo;
        nuevoNodo->siguiente = this->primero;
        this->primero->anterior = nuevoNodo;
        this->primero = nuevoNodo;

        return true;
    }
}

bool TListaCom::InsertarI(TComplejo& nuevo, TListaPos& pos){
    if (pos.EsVacia() || this == nullptr) {
        return false;
    }

    TListaNodo* nuevoNodo = new TListaNodo;
    nuevoNodo->e = nuevo;
    // Insertar el nuevo nodo a la izquierda de la posición indicada
    TListaNodo* nodoActual = pos.pos;
    if (nodoActual->anterior == nullptr) {
        // Si el nodo actual es el primero de la lista, el nuevo nodo será el nuevo primero
        nuevoNodo->siguiente = nodoActual;
        nodoActual->anterior = nuevoNodo;
        this->primero = nuevoNodo;
    } else {
        // Si el nodo actual no es el primero de la lista, insertar el nuevo nodo a la izquierda
        TListaNodo* nodoAnterior = nodoActual->anterior;
        nuevoNodo->siguiente = nodoActual;
        nuevoNodo->anterior = nodoAnterior;
        nodoAnterior->siguiente = nuevoNodo;
        nodoActual->anterior = nuevoNodo;
    }
    return true;
}

bool TListaCom::InsertarD(TComplejo& nuevo, TListaPos& pos){
    if (pos.EsVacia() || this == nullptr) {
        // Si TListaPos es vacío, no se puede insertar
        return false;
    }

    TListaNodo* nuevoNodo = new TListaNodo();
    TListaNodo *nodo = pos.pos;
    nuevoNodo->e = nuevo;

    nuevoNodo->anterior = nodo;
    if (nodo->siguiente != nullptr) {
        nuevoNodo->siguiente = nodo->siguiente;
        nodo->siguiente->anterior = nuevoNodo;
    }
    nodo->siguiente = nuevoNodo;

    if (nodo == this->ultimo) {
        // Si el nodo es el último, actualizar el puntero last
        this->ultimo = nuevoNodo;
    }
    return true;
}

bool TListaCom::Borrar(TComplejo& borrar){
    TListaNodo *nodo = this->primero;

    while (nodo != NULL) {
        // Si se encuentra el elemento a borrar, actualizar los punteros y borrar el nodo
        if (nodo->e == borrar) {
            //Si es el primero
            if (nodo->anterior == nullptr) {
                this->primero = nodo->siguiente;
            } else if (nodo->siguiente == nullptr)
            {
                //Si es el ultimo
                this->ultimo = nodo->anterior;
            }else{
                nodo->anterior->siguiente = nodo->siguiente;
                nodo->siguiente->anterior = nodo->anterior;
            }
            

            delete nodo;
            return true;
        }
        nodo = nodo->siguiente;
    }
    // Si no se encuentra el elemento a borrar, devuelve false
    return false;
}

bool TListaCom::BorrarTodos(TComplejo& borrar){
    TListaNodo *nodo = this->primero;
    bool borrados = false;
    while (nodo != nullptr) {
        // Si se encuentra el elemento a borrar, actualizar los punteros y borrar el nodo
        if (nodo->e == borrar) {
            borrados = Borrar(borrar);
        }
        nodo = nodo->siguiente;
    }
    // Si no se encuentra el elemento a borrar, devuelve false
    return borrados;
}

bool TListaCom::Borrar(TListaPos& p){
    if (p.EsVacia()) {
        return false;
    }

    TListaNodo* nodoBorrar = p.pos;
    TListaNodo* nodo = this->primero;
    while (nodo != nullptr) {
        // Si se encuentra el elemento a borrar, actualizar los punteros y borrar el nodo
        if (nodo->e == nodoBorrar->e) {            
            delete p.pos;
            return Borrar(nodoBorrar->e);
        }
        nodo = nodo->siguiente;
    }

    return false;
}

TComplejo TListaCom::Obtener(TListaPos& pos){
    if (pos.EsVacia()) {
        return TComplejo();
    }

    TListaNodo* nodoObtener = pos.pos;
    TListaNodo* nodo = this->primero;
    while (nodo != nullptr) {
        if (nodo->e == nodoObtener->e) {            
            
            return nodoObtener->e;
        }
        nodo = nodo->siguiente;
    }
    return TComplejo();
}

bool TListaCom::Buscar(TComplejo& num){
    TListaNodo* nodo = this->primero;

    while (nodo != nullptr) {
        if (nodo->e == num) {            
            
            return true;
        }
        nodo = nodo->siguiente;
    }

    return false;
}

int TListaCom::Longitud(){
    int numNodos = 0;
    TListaNodo* nodo = this->primero;

    while (nodo != nullptr) {
        numNodos++;
        nodo = nodo->siguiente;
    }
    return numNodos;
}

TListaPos TListaCom::Primera(){
    TListaPos primero = TListaPos();
    if (this == nullptr)
    {
        return TListaPos();
    }else{
        primero.pos = this->primero;
    }
    
    return primero;
}

TListaPos TListaCom::Ultima(){
    TListaPos ultima = TListaPos();
    if (this == nullptr)
    {
        return TListaPos();
    }else{
        ultima.pos = this->ultimo;
    }
    
    return ultima;
}

bool TListaCom::EsVacia()
{
    return this == nullptr;
}
ostream& operator<<(ostream& os, TListaCom& lista){
    os << "{";

    if(!lista.EsVacia()){
        TListaNodo* nodo = lista.primero;
        while (nodo != nullptr) {
            os << nodo->GetComplejo();

            nodo = nodo->GetSiguiente();
        }
    }

    os << "}";

    return os;
}