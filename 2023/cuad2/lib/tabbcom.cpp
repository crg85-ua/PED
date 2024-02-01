#include "tabbcom.h"

//TNodoABB
TNodoABB::TNodoABB(){
    
}

TNodoABB::TNodoABB(TNodoABB& nodo){
    this->item = nodo.item;
    this->iz = nodo.iz;
    this->de = nodo.de;
}

TNodoABB::~TNodoABB(){

}

TNodoABB& TNodoABB::operator=(TNodoABB& nodo){
    this->item = nodo.item;
    this->iz = nodo.iz;
    this->de = nodo.de;
    return *this;
}

//TABBCom
//Parte pública

TABBCom::TABBCom(){
    this->nodo = nullptr;
}

TABBCom::TABBCom(TABBCom& arbol){
    Copia(arbol);
}

TABBCom::~TABBCom(){
    //free(nodo);
    this->nodo = new TNodoABB();
}

TABBCom& TABBCom::operator=(TABBCom& arbol){
    if (this != &arbol) {
		this->~TABBCom();
		this->Copia(arbol);
	}

	return *this;
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
    if (nodo)
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
    if (EsVacio())
    {
        TNodoABB *aux = new TNodoABB();
		aux->item = nuevoNodo;
		this->nodo = aux;
        insertar = true;
    }else{
        if (!this->Buscar(nuevoNodo))
        {
            if ((this->nodo->item.Mod() > nuevoNodo.Mod()) ||
            (this->nodo->item.Re() > nuevoNodo.Re()) || 
            (this->nodo->item.Re() == nuevoNodo.Re() && 
            this->nodo->item.Im() > nuevoNodo.Im()))
            {
                insertar = this->nodo->iz.Insertar(nuevoNodo);
            }else
            {
                insertar = this->nodo->de.Insertar(nuevoNodo);
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
    return *this;
}

bool TABBCom::Borrar(const TComplejo& borrar){
    bool borrado = false;
    if (this->Buscar(borrar))
    {
        if (this->nodo->iz.EsVacio() && this->nodo->de.EsVacio())
        {
            nodo = nullptr;
            delete nodo;
            borrado = true;
        }else{
            if (!this->nodo->iz.EsVacio() && !this->nodo->de.EsVacio())
            {
                TNodoABB* sustituto = BuscarMaximo(this->nodo->iz);
                borrado = EliminarItem(borrar,sustituto);
            } else{

                TNodoABB *hijo = (nodo->iz.EsVacio()) ? nodo->de.nodo : nodo->iz.nodo;
                TNodoABB *aux = nodo;
                
                nodo->item = hijo->item;
                delete aux;
                aux = nullptr;                         

                borrado = true;                
            }
            
        }
        
    }
    return borrado;
}

TNodoABB* TABBCom::BuscarMaximo(const TABBCom& arbol){
    if (arbol.EsVacio())
    {
        return new TNodoABB();
    }

    if (arbol.nodo->de.EsVacio())
    {
        return arbol.nodo;
    }

    return BuscarMaximo(arbol.nodo->de);  
    
}

bool TABBCom::Buscar(const TComplejo& buscado){
    bool igual = false;

    if (!EsVacio())
    {
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
    }
    
    
    return igual;
    
}

bool TABBCom::EliminarItem(const TComplejo& borrado, TNodoABB* sustituto){
    bool correcto = false;
    if (!EsVacio())
    {   
        if (this->nodo->item == borrado)
        {
            TNodoABB *aux = this->nodo;            
            this->nodo = sustituto;
            sustituto = nullptr;
            aux = nullptr;
        }

        if ((this->nodo->item.Mod() > borrado.Mod()) ||
        (this->nodo->item.Re() > borrado.Re()) || 
        (this->nodo->item.Re() == borrado.Re() && 
        this->nodo->item.Im() > borrado.Im()))
        {
            this->nodo->iz.EliminarItem(borrado,sustituto);
            correcto = true;
        }else
        {
            this->nodo->de.EliminarItem(borrado,sustituto);
            correcto = true;
        }      
           
                 
    }
    
    
    return correcto;
    
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

    return v;
}

ostream& operator<<(ostream& os, TABBCom& arbol){
    os << arbol.Niveles();

    return os;
}
