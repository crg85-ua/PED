#include "../include/tabbcom.h"

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
    this->~TABBCom();
    
    // this->nodo->~TNodoABB();
    // this->nodo = arbol.nodo;
}

bool TABBCom::operator==(const TABBCom& arbol){
    // return this->nodo == arbol.nodo;
}

void TABBCom::InordenAux(TVectorCom& vector, int& num){

}

void TABBCom::PreordenAux(TVectorCom& vector, int& num){

}

void TABBCom::PostordenAux(TVectorCom& vector, int& num){

}

bool TABBCom::EsVacio(){
    if (this->nodo == new TNodoABB() || this->nodo)
    {
        return false;
    }else{
        return true;
    }
    
}

bool TABBCom::Insertar(const TComplejo& nuevoNodo){
    bool insertar = false;
    //NO se podria insertar si ya existe
    //si el elemento es mayor que la raiz
    if (this->EsVacio())
    {
        this->nodo->item = nuevoNodo;
        insertar = true;
    }else{
        if (!this->Buscar(nuevoNodo))
        {
            if ((this->nodo->item.Re() > nuevoNodo.Re()) || 
            (this->nodo->item.Re() == nuevoNodo.Re() && 
            this->nodo->item.Im() > this->nodo->item.Im()))
            {
                insertar = this->nodo->de.Insertar(nuevoNodo);
            }else
            {
                insertar = this->nodo->iz.Insertar(nuevoNodo);
            }            
            
        }
        
    }
    
    return insertar;
}

bool TABBCom::Borrar(const TComplejo& nodo){

}

bool TABBCom::Buscar(const TComplejo& buscado){
    bool igual;

    if (this->nodo->item == buscado)
    {
        igual = true;
    } else{
        if (this->nodo->iz.Buscar(buscado) ||
            this->nodo->de.Buscar(buscado))
        {
            igual = true;
        }else{
            igual = false;
        }
        
    }
    
    return igual;
    
}

TComplejo TABBCom::Raiz(){
    if (EsVacio())
    {
        return TComplejo();
    }else{
        return this->nodo->item;

    }
    
}

int TABBCom::Altura(){

}

int TABBCom::Nodos(){

}

int TABBCom::NodosHoja(){

}

TVectorCom TABBCom::Inorden(){

}

TVectorCom TABBCom::Preorden(){
    
}

TVectorCom TABBCom::Postorden(){
    
}

TVectorCom TABBCom::Niveles(){
    
}

ostream& operator<<(ostream& os, TABBCom& arbol){

}
