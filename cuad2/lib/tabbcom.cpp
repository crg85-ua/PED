#include "tabbcom.h"

//TNodoABB
TNodoABB::TNodoABB(){
    this->item = TComplejo();
    this->iz = TABBCom();
    this->de = TABBCom();
}

TNodoABB::TNodoABB(TNodoABB& nodo){

    this->item = nodo.item;
    this->iz = nodo.iz;
    this->de = nodo.de;
}

TNodoABB::~TNodoABB(){
    this->item = TComplejo();
    this->iz = TABBCom();
    this->de = TABBCom();
}

TNodoABB& TNodoABB::operator=(TNodoABB& nodo){
    this->item = nodo.item;
    this->iz = nodo.iz;
    this->de = nodo.de;
}

bool TNodoABB::operator==(const TNodoABB& nodo){
    if ((this->item == nodo.item) && (this->iz == nodo.iz) && (this->de == nodo.de))
    {
       return true;
    }else{
        return false;
    }
    
    
}

//TABBCom
//Parte privada...
//Parte pública

TABBCom::TABBCom(){
    this->nodo = new TNodoABB();
}

TABBCom::TABBCom(TABBCom& arbol){
    this->nodo = arbol.nodo;
}

TABBCom::~TABBCom(){
    free(nodo);
    this->nodo = new TNodoABB();
}

TABBCom& TABBCom::operator=(TABBCom& arbol){
    this->nodo->~TNodoABB();
    this->nodo = arbol.nodo;
}

bool TABBCom::operator==(const TABBCom& arbol){
    return this->nodo == arbol.nodo;
}

bool EsVacio(){

}

TComplejo TABBCom::Raiz(){
    
}