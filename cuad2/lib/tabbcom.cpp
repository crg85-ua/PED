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
    Copia(arbol);
}

bool TABBCom::operator==(TABBCom& arbol){
    return this->Inorden() == arbol.Inorden();
}

void TABBCom::InordenAux(TVectorCom& vector, int& num){
    if (!this->EsVacio())
    {
        if (this->nodo->iz.EsVacio() && this->nodo->de.EsVacio())
        {
            vector[num] = this->nodo->item;
            num++;
        }else
        {
            this->nodo->iz.InordenAux(vector,num);
            vector[num] = this->nodo->item;
            num++;
            this->nodo->de.InordenAux(vector,num);
        }        
        
    }   

}

void TABBCom::PreordenAux(TVectorCom& vector, int& num){
    if (!this->EsVacio())
    {
        if (this->nodo->iz.EsVacio() && this->nodo->de.EsVacio())
        {
            vector[num] = this->nodo->item;
            num++;
        }else
        {
            vector[num] = this->nodo->item;
            num++;
            this->nodo->iz.PreordenAux(vector,num);
            this->nodo->de.PreordenAux(vector,num);
        }     
        
    }   
}

void TABBCom::PostordenAux(TVectorCom& vector, int& num){
    if (!this->EsVacio())
    {
        if (this->nodo->iz.EsVacio() && this->nodo->de.EsVacio())
        {
            vector[num] = this->nodo->item;
            num++;
        }else
        {
            this->nodo->iz.PreordenAux(vector,num);
            this->nodo->de.PreordenAux(vector,num);
            vector[num] = this->nodo->item;
            num++;
        }     
        
    }
}

bool TABBCom::EsVacio() const{
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
            if ((this->nodo->item.Mod() > nuevoNodo.Mod()) ||
            (this->nodo->item.Re() > nuevoNodo.Re()) || 
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

TABBCom& TABBCom::Copia(const TABBCom& arbol){
    if (!arbol.EsVacio())
    {
        this->nodo = new TNodoABB();
		this->nodo->item = arbol.nodo->item;
		this->nodo->iz.Copia(arbol.nodo->iz);
		this->nodo->de.Copia(arbol.nodo->de);
    } else {
        this->nodo = NULL;
    }
    
}

bool TABBCom::Borrar(const TComplejo& nuevoNodo){
    bool borrado = false;
    if (this->Buscar(nuevoNodo))
    {
        if (this->nodo->iz.EsVacio() && this->nodo->de.EsVacio())
        {
            nodo = new TNodoABB();
            delete nodo;
            borrado = true;
        }else{
            if (!this->nodo->iz.EsVacio() && !this->nodo->de.EsVacio())
            {
                TNodoABB *hijo = BuscarMaximo(this->nodo->iz);
                TNodoABB *aux = nodo;

                nodo = hijo;
                aux->de.nodo = NULL;
                delete aux;
                aux = NULL;
                borrado = true;
            } else{

                TNodoABB *hijo = (nodo->iz.EsVacio()) ? nodo->de.nodo : nodo->iz.nodo;
                TNodoABB *aux = nodo;
                
                nodo = hijo;
                aux->de.nodo = NULL;
                delete aux;
                aux = NULL;                             

                borrado = true;                
            }
            
        }
        
    }
    return borrado;
}

TNodoABB* TABBCom::BuscarMaximo(const TABBCom arbol){
    if (arbol.EsVacio())
    {
        return new TNodoABB();
    }

    if (arbol.nodo->de.EsVacio())
    {
        return arbol.nodo->de.nodo;
    }

    return BuscarMaximo(arbol.nodo->de);  
    
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
    if (this->EsVacio())
    {
        return 0;
    }else{
        return 1 + max(this->nodo->iz.Altura(),this->nodo->de.Altura());
    }
}

int TABBCom::Nodos(){
    if (this->EsVacio())
    {
        return 0;
    }else{
        return 1 + this->nodo->iz.Nodos() + this->nodo->de.Nodos();
    }
    
}

int TABBCom::NodosHoja(){
    if (!EsVacio())
    {
        if (nodo->iz.EsVacio() && nodo->de.EsVacio())
        {
            return 1;
        } else{
            return nodo->iz.NodosHoja() + nodo->de.NodosHoja();
        }
        
    } else{
        return 0;
    }
    
}

TVectorCom TABBCom::Inorden(){
    int pos = 1;

    TVectorCom v(Nodos());
    InordenAux(v,pos);
    return v;
}

TVectorCom TABBCom::Preorden(){
    int pos = 1;

    TVectorCom v(Nodos());
    PreordenAux(v,pos);
    return v;
}

TVectorCom TABBCom::Postorden(){
    int pos = 1;

    TVectorCom v(Nodos());
    PostordenAux(v,pos);
    return v;
}

TVectorCom TABBCom::Niveles(){
    TVectorCom v(this->Nodos());
    int posicion = 1;
    queue<TNodoABB*> cola;
    cola.push(this->nodo);

    while(!cola.empty()){
        TNodoABB *aux = cola.front();
        v[posicion] = (*aux).item;
        posicion++;

        cola.pop();

        if (!(*aux).iz.EsVacio())
        {
            cola.push((*aux).iz.nodo);
        }
        if (!(*aux).de.EsVacio())
        {
             cola.push((*aux).de.nodo);
        }
    }
}

ostream& operator<<(ostream& os, TABBCom& arbol){
    os << arbol.Niveles();

    return os;
}
