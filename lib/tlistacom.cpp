#include "tcomplejo.h"
#include "tvectorcom.h"
#include "tlistacom.h"

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
    anterior.pos = pos-1;
    return anterior;
}

TListaPos TListaPos::Siguiente(){
    TListaPos siguiente = TListaPos();
    siguiente.pos = pos+1;
    return siguiente;
}

bool TListaPos::EsVacia(){
    
}


