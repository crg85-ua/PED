#include "tavlcalendario.h"

//TNodoAvl
TNodoAVL::TNodoAVL(){
    this->fe = 0;
    this->iz = TAVLCalendario();
    this->de = TAVLCalendario();
    this->item = TCalendario();
}

//TNodoAvl
TNodoAVL::TNodoAVL(TNodoAVL& nodo){
    this->fe = nodo.fe;
    this->iz = nodo.iz;
    this->de = nodo.de;
    this->item = nodo.item;
}

TNodoAVL::~TNodoAVL(){
    this->fe = 0;
    this->iz.~TAVLCalendario();
    this->de.~TAVLCalendario();
    this->item = TCalendario();
}

TNodoAVL& TNodoAVL::operator=(TNodoAVL& nodo){
    if(this != &nodo){
        this->~TNodoAVL();
        this->fe = nodo.fe;
        this->iz = nodo.iz;
        this->de = nodo.de;
        this->item = nodo.item;
    }
    return *this;
}


// Constructor por defecto
TAVLCalendario::TAVLCalendario() {
    this->raiz = NULL;
}

// Constructor de copia
TAVLCalendario::TAVLCalendario( TAVLCalendario& avl) {
    if (avl.raiz != NULL) {
        this->raiz = new TNodoAVL(*avl.raiz);
    } else {
        this->raiz = NULL;
    }    
}

// Destructor
TAVLCalendario::~TAVLCalendario() {
    if (this->raiz != NULL) {
        delete this->raiz;
        this->raiz = NULL;
    }
}

// Sobrecarga del operador de asignación
TAVLCalendario& TAVLCalendario::operator=( const TAVLCalendario& avl) {
    if (this != &avl) {
        if (this->raiz != NULL) {
            delete this->raiz;
            this->raiz = NULL;
        }
        if (avl.raiz != NULL) {
            this->raiz = new TNodoAVL(*avl.raiz);
        }
    }
    return *this;
}

// Sobrecarga del operador de comparación igualdad
bool TAVLCalendario::operator==( TAVLCalendario& avl) {   
    if (this->raiz == NULL && avl.raiz == NULL) {
        return true;
    } else if (this->raiz != NULL && avl.raiz != NULL) {
        TVectorCalendario v1 = this->Inorden();
        TVectorCalendario v2 = avl.Inorden();
        return v1 == v2;
    } else {
        return false;
    }
    
    return false;
}

// Sobrecarga del operador de comparación desigualdad
bool TAVLCalendario::operator!=( TAVLCalendario& avl ) {
    return !(*this == avl);
}
//Indica si el árbol está vacio
bool TAVLCalendario::EsVacio(){
    return this->raiz == NULL;

}


bool TAVLCalendario::Insertar(const TCalendario& cal) {
    if (this->raiz == NULL) {
        this->raiz = new TNodoAVL();
        this->raiz->item = cal;
        return true;
    } else if (cal < this->raiz->item) {
        bool inserted = this->raiz->iz.Insertar(cal);
        if (inserted) {
            int v = this->raiz->iz.Altura() - this->raiz->de.Altura();
            if (this->raiz->iz.Altura() - this->raiz->de.Altura() == 2) {
                if (cal < this->raiz->iz.raiz->item) {
                    this->RotacionII();
                } else {
                    this->RotacionID();
                }
            }
            return true;
        } else {
            return false;
        }
    } else if (cal > this->raiz->item) {
        bool inserted = this->raiz->de.Insertar(cal);
        if (inserted) {
            if (this->raiz->de.Altura() - this->raiz->iz.Altura() == 2) {
                if (cal > this->raiz->de.raiz->item) {
                    this->RotacionDD();
                } else {
                    this->RotacionDI();
                }
            }
            return true;
        } else {
            return false;
        }
    } else {
        return false; // Element already exists in the tree
    }
}

void TAVLCalendario::RotacionII() {
    TNodoAVL *aux = this->raiz->iz.raiz;
    this->raiz->iz.raiz = aux->de.raiz;
    aux->de.raiz = this->raiz;
    this->raiz = aux;

    // Update fe values
    this->raiz->de.raiz->fe = max(this->raiz->de.raiz->iz.Altura(), this->raiz->de.raiz->de.Altura()) + 1;
    this->raiz->fe = max(this->raiz->iz.Altura(), this->raiz->de.Altura()) + 1;
}

void TAVLCalendario::RotacionDD() {
    TNodoAVL *aux = this->raiz->de.raiz;
    this->raiz->de.raiz = aux->iz.raiz;
    aux->iz.raiz = this->raiz;
    this->raiz = aux;

    // Update fe values
    this->raiz->iz.raiz->fe = max(this->raiz->iz.raiz->iz.Altura(), this->raiz->iz.raiz->de.Altura()) + 1;
    this->raiz->fe = max(this->raiz->iz.Altura(), this->raiz->de.Altura()) + 1;
}

void TAVLCalendario::RotacionID() {
    this->raiz->iz.RotacionDD();
    this->RotacionII();

    // Update fe values
    this->raiz->iz.raiz->fe = max(this->raiz->iz.raiz->iz.Altura(), this->raiz->iz.raiz->de.Altura()) + 1;
    this->raiz->de.raiz->fe = max(this->raiz->de.raiz->iz.Altura(), this->raiz->de.raiz->de.Altura()) + 1;
    this->raiz->fe = max(this->raiz->iz.Altura(), this->raiz->de.Altura()) + 1;
}

void TAVLCalendario::RotacionDI() {
    this->raiz->de.RotacionII();
    this->RotacionDD();

    // Update fe values
    this->raiz->iz.raiz->fe = max(this->raiz->iz.raiz->iz.Altura(), this->raiz->iz.raiz->de.Altura()) + 1;
    this->raiz->de.raiz->fe = max(this->raiz->de.raiz->iz.Altura(), this->raiz->de.raiz->de.Altura()) + 1;
    this->raiz->fe = max(this->raiz->iz.Altura(), this->raiz->de.Altura()) + 1;
}



bool TAVLCalendario::Borrar(TCalendario& cal) {
    if (this->raiz == NULL) {
        return false; // Element not found in the tree
    } else if (cal < this->raiz->item) {
        bool deleted = this->raiz->iz.Borrar(cal);
        if (deleted) {
            if (this->raiz->de.Altura() - this->raiz->iz.Altura() == 2) {
                if (this->raiz->de.raiz->iz.Altura() > this->raiz->de.raiz->de.Altura()) {
                    this->RotacionDI();
                } else {
                    this->RotacionDD();
                }
            }
            return deleted;
        } else {
            return deleted;
        }
    } else if (cal > this->raiz->item) {
        bool deleted = this->raiz->de.Borrar(cal);
        if (deleted) {
            if (this->raiz->iz.Altura() - this->raiz->de.Altura() == 2) {
                if (this->raiz->iz.raiz->de.Altura() > this->raiz->iz.raiz->iz.Altura()) {
                    this->RotacionID();
                } else {
                    this->RotacionII();
                }
            }
            return true;
        } else {
            return false;
        }
    } else {
        if (this->raiz->iz.raiz == NULL && this->raiz->de.raiz == NULL) {
            delete this->raiz;
            this->raiz = NULL;
        } else if (this->raiz->iz.raiz == NULL) {
            TNodoAVL *aux = this->raiz;
            this->raiz = this->raiz->de.raiz;
            aux->de.raiz = NULL;
            delete aux;
        } else if (this->raiz->de.raiz == NULL) {
            TNodoAVL *aux = this->raiz;
            this->raiz = this->raiz->iz.raiz;
            aux->iz.raiz = NULL;
            delete aux;
        } else {
            TCalendario aux = this->raiz->iz.Maximo();
            this->raiz->item = aux;
            this->raiz->iz.Borrar(aux);
            if (this->raiz->de.Altura() - this->raiz->iz.Altura() == 2) {
                if (this->raiz->de.raiz->iz.Altura() > this->raiz->de.raiz->de.Altura()) {
                    this->RotacionDI();
                } else {
                    this->RotacionDD();
                }
            }
        }
        return true;
    }
}


// Devuelve true si el elemento está en el árbol, false en caso contrario
bool TAVLCalendario::Buscar( TCalendario& cal)  {
    if(this->raiz != NULL){
        if(this->raiz->item == cal){
            return true;
        }else{
            if(this->raiz->item < cal){
                return this->raiz->de.Buscar(cal);
            }else{
                return this->raiz->iz.Buscar(cal);
            }
        }
    }    
    return false;
}

// Devuelve la altura del árbol
int TAVLCalendario::Altura()  {
    if (this->raiz == NULL) {
        return 0;
    } else {
        return 1 + max(this->raiz->iz.Altura(), this->raiz->de.Altura());
    }
}

// Devuelve el número de nodos del árbol (un árbol vacío tiene 0 nodos)
int TAVLCalendario::Nodos()  const{
    if (this->raiz == NULL){
        return 0;
    } else {
        return 1 + this->raiz->iz.Nodos() + this->raiz->de.Nodos();
    }
    
    return 0;
}

// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TAVLCalendario::NodosHoja() {
    if(this->raiz != NULL){
        if(this->raiz->iz.raiz == NULL && this->raiz->de.raiz == NULL){
            return 1;
        }else{
            return this->raiz->iz.NodosHoja() + this->raiz->de.NodosHoja();
        }
    }
    return 0;
}

// Devuelve el recorrido en inorden sobre un vector
TVectorCalendario TAVLCalendario::Inorden() const  {
    TVectorCalendario v(this->Nodos());
    int p = 1;
    InordenAux(v,p);
    return v;
}

// Devuelve el recorrido en preorden sobre un vector
TVectorCalendario TAVLCalendario::Preorden() const {
    TVectorCalendario v(this->Nodos());
    int p = 1;
    PreordenAux(v, p);
    return v;
}

// Devuelve el recorrido en postorden sobre un vector
TVectorCalendario TAVLCalendario::Postorden() const {
    TVectorCalendario v(this->Nodos());
    int p = 1;
    PostordenAux(v, p);
    return v;
}

void TAVLCalendario::InordenAux(TVectorCalendario &v, int& p) const{
    if (this->raiz != NULL) {
        this->raiz->iz.InordenAux(v, p);
        v[p] = this->raiz->item;
        p++;
        this->raiz->de.InordenAux(v, p);
    }
}

void TAVLCalendario::PreordenAux(TVectorCalendario &v, int& p) const{
    if (this->raiz != NULL) {
        v[p] = this->raiz->item;
        p++;
        this->raiz->iz.PreordenAux(v, p);
        this->raiz->de.PreordenAux(v, p);
    }
}

void TAVLCalendario::PostordenAux(TVectorCalendario &v, int& p) const{
    if (this->raiz != NULL) {
        this->raiz->iz.PostordenAux(v, p);
        this->raiz->de.PostordenAux(v, p);
        v[p] = this->raiz->item;
        p++;
    }
}

TCalendario TAVLCalendario::Raiz(){
    if(this->raiz != NULL){
        return this->raiz->item;
    }
    return TCalendario();

}

// Sobrecarga del operador de salida
ostream& operator<<(ostream& os, TAVLCalendario& avl) {
    os << avl.Inorden();
    return os;
}

// Devuelve el máximo TCalendario del árbol
TCalendario TAVLCalendario::Maximo() const {
    if (this->raiz == NULL) {
        return TCalendario();
    } else if (this->raiz->de.raiz == NULL) {
        return this->raiz->item;
    } else {
        return this->raiz->de.Maximo();
    }
}

int* TAVLCalendario::BuscaAVL(TListaCalendario& lista){
    int* resultado = new int(lista.Longitud());

    if(lista.EsVacia()){
        return resultado = NULL;
    }

    BuscaAVLAux(resultado, 0, "ra", lista);
    
    return resultado;
}

void TAVLCalendario::BuscaAVLAux(int* num, int p, char* arb, TListaCalendario& lista){
    if (this->raiz != NULL) {
        this->raiz->iz.BuscaAVLAux(num, p, "iz", lista);
        this->raiz->de.BuscaAVLAux(num, p, "de", lista);
        
        if(lista.Obtener(lista.Primera().Siguiente()) == this->raiz->item){
            if (arb == "iz")
            {
                num[p] = 1;
            } else if (arb == "de")
            {
                num[p] = 2;
            } else if(arb == "ra"){
                num[p] = 3;
            }
            
            
        }else {
            num[p] = 0;
        }
        
        p++;
    }
}