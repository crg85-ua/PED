#include "tavlcom.h"

TNodoAVL::TNodoAVL(){
    this->item = TComplejo();
    this->iz = TAVLCom();
    this->de = TAVLCom();
    this->fe = 0;
}

TNodoAVL::TNodoAVL(TNodoAVL& nodo){
    *this = nodo;
}

TNodoAVL::~TNodoAVL(){
    this->item = TComplejo();
    this->iz = TAVLCom();
    this->de = TAVLCom();
    this->fe = 0;
}

TNodoAVL& TNodoAVL::operator=(const TNodoAVL& nodo) {
    if ( this != &nodo)
    {
        this->item = nodo.item;
        this->iz = nodo.iz;
        this->de = nodo.de;
        this->fe = nodo.fe;
    }

    return *this;    
}

TAVLCom::TAVLCom(){
    this->raiz = new TNodoAVL();
}

TAVLCom::TAVLCom(const TAVLCom& arbol){
    this->raiz = arbol.raiz;
}

TAVLCom::~TAVLCom(){
    this->raiz = new TNodoAVL();
}

TAVLCom& TAVLCom::operator=(const TAVLCom& arbol) const{

}

bool TAVLCom::operator==(TAVLCom& arbol){

}

bool TAVLCom::operator!=(TAVLCom& arbol){

}

bool TAVLCom::EsVacio(){

}

bool TAVLCom::Insertar(TComplejo& nodo){

}

bool TAVLCom::Buscar(TComplejo& nodo){

}

bool TAVLCom::Borrar(TComplejo& nodo){

}

int TAVLCom::Altura(){

}

TComplejo TAVLCom::Raiz(){

}

int TAVLCom::Nodos(){

}

int TAVLCom::NodosHoja(){

}

TVectorCom TAVLCom::Inorden(){

}

TVectorCom TAVLCom::Preorden(){

}

TVectorCom TAVLCom::Postorden(){

}

ostream& operator<<(ostream& os, TAVLCom& arbol){

}
