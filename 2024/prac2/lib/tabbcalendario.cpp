#include "../include/tabbcalendario.h"
#include "tcalendario.h"

// Implement the functions of the TNodoABB class here

// Constructor
TNodoABB::TNodoABB(){
    //Check
    item = TCalendario();
    iz = TABBCalendario();
    de = TABBCalendario();
}

// Destructor
TNodoABB::~TNodoABB() {
    //Check
    item = TCalendario();
    iz.~TABBCalendario();
    de.~TABBCalendario();
}

// Copy constructor
TNodoABB::TNodoABB(const TNodoABB &node) {
    //Check
    item = node.item;
    iz = node.iz;
    de = node.de;
}

// Assignment operator
TNodoABB &TNodoABB::operator=(const TNodoABB &node)
{
    //Check
    if (this != &node)
    {
        this->~TNodoABB();
        item = node.item;
        iz = node.iz;
        de = node.de;
    }
    return *this;
}


//TABBCALENDARIO

// Implement the functions of the TNodoABB class here

// Constructor
TABBCalendario::TABBCalendario(){
    //Check
    raiz = NULL;
}

// Destructor
TABBCalendario::~TABBCalendario(){
    //Check
    if(raiz != NULL){
        delete raiz;
        raiz = NULL;
    }
}

// Copy constructor
TABBCalendario::TABBCalendario(const TABBCalendario &abb){
    //Check    
    if(abb.raiz != NULL && !abb.EsVacio()){
        raiz = new TNodoABB(*abb.raiz);
    }
    else{
        raiz = NULL;
    }

    return *this;
}

// Assignment operator
TABBCalendario &TABBCalendario::operator=(const TABBCalendario &abb){
    //Check
    if(this != &abb){
        this->~TABBCalendario();
        if(abb.raiz != NULL){
            raiz = new TNodoABB(*abb.raiz);
        }
        else{
            raiz = NULL;
        }
    }
    return *this;
}

// Insert a TCalendario into the tree
bool TABBCalendario::Insertar(const TCalendario &cal){
    //Check
    if(EsVacio()){
        raiz = new TNodoABB();
        raiz->item = cal;
        return true;
    }
    else if(cal < raiz->item){
        return raiz->iz.Insertar(cal);
    }
    else if(cal > raiz->item){
        return raiz->de.Insertar(cal);
    }
    else{
        return false;
    }
}

// Remove a TCalendario from the tree
bool TABBCalendario::Borrar(const TCalendario &cal){
    //Check
    if(!EsVacio()){
        if(cal == raiz->item){
            if(raiz->iz.EsVacio() && raiz->de.EsVacio()){
                delete raiz;
                raiz = NULL;
            }
            else if(raiz->iz.EsVacio()){
                TNodoABB *aux = raiz;
                raiz = raiz->de.raiz;
                aux->de.raiz = NULL;
                delete aux;
            }
            else if(raiz->de.EsVacio()){
                TNodoABB *aux = raiz;
                raiz = raiz->iz.raiz;
                aux->iz.raiz = NULL;
                delete aux;
            }
            else{
                TCalendario cal;
                raiz->de.Minimo(cal);
                raiz->item = cal;
                raiz->de.Borrar(cal);
            }
            return true;
        }
        else if(cal < raiz->item){
            return raiz->iz.Borrar(cal);
        }
        else{
            return raiz->de.Borrar(cal);
        }
    }
    return false;
}

// Check if the tree is empty
bool TABBCalendario::EsVacio() const{
    //Check
    return raiz == NULL;
}

// Find a TCalendario in the tree
bool TABBCalendario::Buscar(const TCalendario &cal) const{
    //Check
    if(!EsVacio()){
        if(cal == raiz->item){
            return true;
        }
        else if(cal < raiz->item){
            return raiz->iz.Buscar(cal);
        }
        else{
            return raiz->de.Buscar(cal);
        }
    }
    return false;
}

// Get the minimum TCalendario in the tree
bool TABBCalendario::Minimo(TCalendario &cal) const{
    //Check
    if(!EsVacio()){
        if(raiz->iz.EsVacio()){
            cal = raiz->item;
            return true;
        }
        else{
            return raiz->iz.Minimo(cal);
        }
    }
    return false;
}

// Get the maximum TCalendario in the tree
bool TABBCalendario::Maximo(TCalendario &cal) const{
    //Check
    if(!EsVacio()){
        if(raiz->de.EsVacio()){
            cal = raiz->item;
            return true;
        }
        else{
            return raiz->de.Maximo(cal);
        }
    }
    return false;
}

// Get the height of the tree
int TABBCalendario::Altura() const{
    //Check
    if(EsVacio()){
        return 0;
    }
    else{
        int altura_iz = raiz->iz.Altura();
        int altura_de = raiz->de.Altura();
        return 1 + (altura_iz > altura_de ? altura_iz : altura_de);
    }
}

// Get the number of nodes in the tree
int TABBCalendario::Nodos() const{
    //Check
    if(EsVacio()){
        return 0;
    }
    else{
        return 1 + raiz->iz.Nodos() + raiz->de.Nodos();
    }
}

// Get the number of leaf nodes in the tree
int TABBCalendario::NodosHoja() const{
    //Check
    if(EsVacio()){
        return 0;
    }
    else if(raiz->iz.EsVacio() && raiz->de.EsVacio()){
        return 1;
    }
    else{
        return raiz->iz.NodosHoja() + raiz->de.NodosHoja();
    }
}

// In-order traversal of the tree
TVectorCalendario TABBCalendario::Inorden() const{
    //Check
    if(!EsVacio()){
        int pos = 1;
        TVectorCalendario vec(Nodos());
        InordenAux(vec, pos);
        return vec;
    }
}

// In-order traversal of the tree with position
void TABBCalendario::InordenAux(TVectorCalendario &vec, int &pos) const{
    //Check
    if(!EsVacio()){
        raiz->iz.InordenAux(vec, pos);
        vec[pos] = raiz->item;
        pos++;
        raiz->de.InordenAux(vec, pos);
    }
}

// Pre-order traversal of the tree
TVectorCalendario TABBCalendario::Preorden() const{
    //Check
    if(!EsVacio()){
        int pos = 1;
        TVectorCalendario vec(Nodos());
        PreordenAux(vec, pos);
        return vec;
    }
}

// Pre-order traversal of the tree with position
void TABBCalendario::PreordenAux(TVectorCalendario &vec, int &pos) const{
    //Check
    if(!EsVacio()){
        vec[pos] = raiz->item;
        pos++;
        raiz->iz.PreordenAux(vec, pos);
        raiz->de.PreordenAux(vec, pos);
    }
}

// Post-order traversal of the tree
TVectorCalendario TABBCalendario::Postorden() const{
    //Check
    if(!EsVacio()){
        int pos = 1;
        TVectorCalendario vec(Nodos());
        PostordenAux(vec, pos);
        return vec;
    }
}

// Post-order traversal of the tree with position
void TABBCalendario::PostordenAux(TVectorCalendario &vec, int &pos) const{
    //Check
    if(!EsVacio()){
        raiz->iz.PostordenAux(vec, pos);
        raiz->de.PostordenAux(vec, pos);
        vec[pos] = raiz->item;
        pos++;
    }
}

// Level-order traversal of the tree
TVectorCalendario TABBCalendario::Niveles() const{
    //Check
    if(!EsVacio()){
        TVectorCalendario vec(Nodos());
        queue<TNodoABB*> cola;
        cola.push(raiz);
        int pos = 1;
        while(!cola.empty()){
            TNodoABB *nodo = cola.front();
            cola.pop();
            vec[pos] = nodo->item;
            pos++;
            if(!nodo->iz.EsVacio()){
                cola.push(nodo->iz.raiz);
            }
            if(!nodo->de.EsVacio()){
                cola.push(nodo->de.raiz);
            }
        }
    }
}

