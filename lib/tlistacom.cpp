#include "tcomplejo.h"
#include "tvectorcom.h"
#include "tlistacom.h"

const int POS_ACTUAL = 0;
const int POS_SIG_ANT = 1;

//TLISTANODO
TListaNodo::TListaNodo() : e(){
    anterior = new TListaNodo();
    siguiente = new TListaNodo();

}

TListaNodo::TListaNodo(TListaNodo& nodo) : e(nodo.e){
    anterior = nodo.anterior;
    siguiente = nodo.siguiente;
}

TListaNodo::~TListaNodo(){
    e.~TComplejo();
    delete anterior;
    delete siguiente;
}

TListaNodo& TListaNodo::operator=(TListaNodo& nodo){
    this->e = nodo.e;
    this->siguiente = nodo.siguiente;
    this->anterior = nodo.anterior;

    return *this;
}

bool TListaNodo::operator!=(TListaNodo& nodo){
    if (this->e != nodo.e || this->siguiente != nodo.siguiente || this->anterior != nodo.anterior)
    {
        return true;
    }else{
        return false;
    }
    
}

//TLISTAPOS
TListaPos::TListaPos(){
    pos = new TListaNodo();
}

TListaPos::TListaPos(TListaPos& pos){
    this->pos = pos.pos;
}

TListaPos::~TListaPos(){
    delete pos;
}

TListaPos& TListaPos::operator=(TListaPos& posicion){
    pos = posicion.pos;
}

bool TListaPos::operator==(TListaPos& posicion){
    return &pos == &posicion.pos;    
}

bool TListaPos::operator!=(TListaPos& posicion){
    return &pos != &posicion.pos;
}

TListaPos TListaPos::Anterior(){
    TListaPos anterior = TListaPos();
    anterior.pos = pos-POS_SIG_ANT;
    return anterior;
}

TListaPos TListaPos::Siguiente(){
    TListaPos siguiente = TListaPos();
    siguiente.pos = pos+POS_SIG_ANT;
    return siguiente;
}

bool TListaPos::EsVacia(){
    return pos == nullptr;
}

//TLISTACOM

TListaCom::TListaCom(){
    primero = new TListaNodo();
    ultimo = new TListaNodo();
}


TListaCom::TListaCom(TListaCom& lista){
    this->primero = lista.primero;
    this->ultimo = lista.ultimo;
}

TListaCom::~TListaCom(){
    delete primero;
    delete ultimo;
}

TListaCom& TListaCom::operator=(TListaCom& lista){
    this->primero = lista.primero;
    this->ultimo = lista.ultimo;

    return *this;
}

bool TListaCom::operator==(TListaCom& lista){


    while (this->primero != nullptr || this->primero != this->ultimo)
    {
       if (*(this->primero+POS_ACTUAL) != *(lista.primero+POS_ACTUAL))
       {
            return false;
       }
       
       this->primero = this->primero+POS_SIG_ANT;
    }
    
    return true;

}

bool TListaCom::operator!=(TListaCom& lista){
    while (this->primero != nullptr || this->primero != this->ultimo)
    {
    if (*(this->primero+POS_ACTUAL) != *(lista.primero+POS_ACTUAL))
    {
        return true;
    }
    
    this->primero = this->primero+POS_SIG_ANT;
    }
        
    return false;

}

TListaCom TListaCom::operator+(TListaCom& lista){


}

