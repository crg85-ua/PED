#include "../include/tavlcom.h"

// FORMA CANÓNICA
// Constructor por defecto
TNodoAVL::TNodoAVL () 
{ 
    this->fe = 0;
}
// Constructor de copia
TNodoAVL::TNodoAVL (TNodoAVL &other)
{
    this->fe = other.fe;
    this->item = other.item;
    this->de = other.de;
    this->iz = other.iz;
}
// Destructor 
TNodoAVL::~TNodoAVL ()
{
    this->fe = 0;
}
// Sobrecarga del operador asignación 
TNodoAVL & TNodoAVL::operator=( TNodoAVL &node)
{
    if (this != &node) {
		this->item = node.item;
		this->de = node.de;
		this->iz = node.iz;
	}

	return *this;
}

/////////////////////////////////////////////////////////////////////////

void TAVLCom::Sustituir() {
    TNodoAVL *anterior = nullptr;
    TNodoAVL *posterior = nullptr;
    TNodoAVL *actual = this->raiz;

    posterior = this->raiz->iz.raiz;

    if (posterior->de.EsVacio()) {
        actual->item = posterior->item;
        actual->iz.raiz = posterior->iz.raiz;
    } else {
        while (!posterior->de.EsVacio()) {
            anterior = posterior;
            posterior = posterior->de.raiz;
        }

        anterior->de.raiz = posterior->iz.raiz;
        actual->item = posterior->item;
    }
}

// AUXILIAR: Devuelve el recorrido en inorden void 
void TAVLCom::InordenAux(TVectorCom &vec, int &i) const
{
    if (!this->EsVacio()) {
		if ((this->raiz->de.EsVacio() && this->raiz->iz.EsVacio())){
			vec[i] = this->raiz->item;
			i++;
		} else {
			this->raiz->iz.InordenAux(vec, i);
			vec[i] = this->raiz->item;
			i++;
			this->raiz->de.InordenAux(vec, i);
		}
	}
}

// AUXILIAR: Devuelve el recorrido en preorden void 
void TAVLCom::PreordenAux(TVectorCom &vec, int &i) const
{
    if (this->EsVacio()) return;

    vec[i] = this->raiz->item;
    i++;
    if (!(this->raiz->de.EsVacio() && this->raiz->iz.EsVacio())) {
        this->raiz->iz.PreordenAux(vec, i);
        this->raiz->de.PreordenAux(vec, i);
    }
}
// AUXILIAR: Devuelve el recorrido en postorden void 
void TAVLCom::PostordenAux(TVectorCom &vec, int &i) const
{
    if (!(this->raiz->de.EsVacio() && this->raiz->iz.EsVacio())) {
        this->raiz->iz.PostordenAux(vec, i);
        this->raiz->de.PostordenAux(vec, i);
    }
    vec[i] = this->raiz->item;
    i++;
}
//FORMA CANÓNICA
// Constructor por defecto
TAVLCom::TAVLCom ()
{
    this->raiz = NULL;
}
// Constructor de copia
TAVLCom::TAVLCom (const TAVLCom &avl)
{
	if (!avl.EsVacio()) {
        this->Replicate(avl);
	} else
		this->raiz = NULL;
}
// Destructor 
TAVLCom::~TAVLCom ()
{

}

void TAVLCom::Replicate(const TAVLCom &avl) {
	if (avl.EsVacio()) { this->raiz = NULL; return; }

    this->raiz = new TNodoAVL();
    this->raiz->item = avl.raiz->item;
    this->raiz->de.Replicate(avl.raiz->de);
    this->raiz->iz.Replicate(avl.raiz->iz);
}

// Sobrecarga del operador asignación 
TAVLCom & TAVLCom::operator=(const TAVLCom & avl)
{
    if (this == &avl) return *this;
    this->~TAVLCom();
    this->Replicate(avl);
    return *this;
}
//MÉTODOS
// Sobrecarga del operador igualdad 
bool TAVLCom::operator==(const TAVLCom &avl) const
{
    return (this->Inorden() == avl.Inorden());
}
// Sobrecarga del operador desigualdad 
bool TAVLCom::operator!=(const TAVLCom & avl) const
{
    return !(this->Inorden() == avl.Inorden());
}
// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario  
bool TAVLCom::EsVacio() const
{
    return (this->raiz == NULL);
}
// Inserta el elemento TComplejo en el árbol
bool TAVLCom::Insertar(TComplejo & comp)
{
    bool ins = false;
    if(this->EsVacio()){
		TNodoAVL *aux = new TNodoAVL();
		aux->item = comp;
		this->raiz = aux;
		ins = true;
	}

    if(this->Buscar(comp)){
        return false;
    }

    if(this->Greater(comp))
        ins = this->raiz->de.Insertar(comp);
    else
        ins = this->raiz->iz.Insertar(comp);

    if(ins) 
    {
        update("fe");
    }

    return ins;
}

void TAVLCom::update(std::string what)
{
    if(what == "fe")
    {
        if (EsVacio()) return;
        
		this->raiz->fe = raiz->de.Altura() - raiz->iz.Altura();
		if (!raiz->de.EsVacio())
			raiz->de.update("fe");
		if (!raiz->iz.EsVacio())
			raiz->iz.update("fe");
    }
    else if(what == "check")
    {
        if (!raiz->iz.EsVacio()) {
            raiz->iz.update("check");
        }
        if (!raiz->de.EsVacio()) {
            raiz->de.update("check");
        }

        if (raiz->fe == 2) {
            if (raiz->de.raiz->fe == 1 || raiz->de.raiz->fe == 0) {
                //reestructurarRR();
                restucture("right");
            }
            if (raiz->de.raiz->fe == -1) {
                //reestructurarRL();
                restucture("right-left");
            }
        } else if (this->raiz->fe == -2) {
            if (this->raiz->iz.raiz->fe == 1) {
                //reestructurarLR();
                restucture("left-right");
            } else if (this->raiz->iz.raiz->fe == -1 || raiz->iz.raiz->fe == 0) {
                //reestructurarLL();
                restucture("left");
            }
        }
    }
}

void TAVLCom::restucture(std::string what)
{
    if(what == "left-right") 
    {
        this->raiz->iz.restucture("right");
        restucture("left");
    }
    else if("right-left")
    {
        this->raiz->de.restucture("left");
        restucture("right");
    }
    else if("right")
    {
        TNodoAVL *aux = raiz->de.raiz->iz.raiz;
        raiz->de.raiz->iz.raiz = raiz;
        raiz->de.raiz->fe = 0;
        TNodoAVL *aux2 = raiz->de.raiz;
        raiz->de.raiz = aux;
        raiz->fe = 0;
        raiz = aux2;
    }
    else if("left")
    {
        TNodoAVL *aux = raiz->iz.raiz->de.raiz;
        raiz->iz.raiz->de.raiz = raiz;
        raiz->iz.raiz->fe = 0;
        TNodoAVL *aux2 = raiz->iz.raiz;
        raiz->iz.raiz = aux;
        raiz->fe = 0;
        raiz = aux2;
    }
}

bool TAVLCom::Greater(TComplejo complejo) const {
    if (complejo == raiz->item) { // if the complex number is the same as the node's item, it's not greater
        return false;
    }
    else if (complejo.Mod() < raiz->item.Mod()) { // if the complex number's modulus is less than the node's item, it's not greater
        return false;
    }
    else if (complejo.Mod() > raiz->item.Mod()) { // if the complex number's modulus is greater than the node's item, it's greater
        return true;
    }
    else if (complejo.Re() < raiz->item.Re()) { // if the complex number's modulus is equal to the node's item, but its real part is less, it's not greater
        return false;
    }
    else if (complejo.Re() > raiz->item.Re()) { // if the complex number's modulus is equal to the node's item, but its real part is greater, it's greater
        return true;
    }
    else if (complejo.Im() < raiz->item.Im()) { // if the complex number's modulus and real part are equal to the node's item, but its imaginary part is less, it's not greater
        return false;
    }
    else { // if the complex number's modulus and real part are equal to the node's item, but its imaginary part is greater, it's greater
        return true;
    }
}

// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario 
bool TAVLCom::Buscar(TComplejo & com)
{
    if (EsVacio()) return false;

    if (this->raiz->item == com)
        return true;
    else {
        if (this->raiz->iz.Buscar(com) || this->raiz->de.Buscar(com)) return true;
    }
	return false;
}
// Borra un TComplejo del árbol AVL
bool TAVLCom::Borrar(TComplejo &complejo)
{
    bool removed = false;

    if (this->Buscar(complejo)) {
        if (this->raiz->item == complejo) {
            if (this->raiz->de.EsVacio() && this->raiz->iz.EsVacio()) {
                delete this->raiz;
                this->raiz = NULL;

                removed = true;
            } else if (this->raiz->iz.EsVacio() || this->raiz->de.EsVacio()) {
                TNodoAVL* temp = this->raiz;

                if (this->raiz->iz.EsVacio()) {
                    this->raiz = this->raiz->de.raiz;
                } else {
                    this->raiz = this->raiz->iz.raiz;
                }

                delete temp;
                temp->iz.raiz = NULL;
                temp->de.raiz = NULL;

                temp = NULL;
                removed = true;
            } else {
                this->Sustituir();

                removed = true;
            }
        } else {
            if (!this->Greater(complejo)) {
                removed = this->raiz->iz.Borrar(complejo);
            } else {
                removed = this->raiz->de.Borrar(complejo);
            }
        }
    }
    return removed;
}
// Devuelve la altura del árbol (la altura de un árbol vacío es 0) 
int TAVLCom::Altura() const
{
    if (this->EsVacio()) return 0;
    return 1 + std::max(raiz->iz.Altura(), raiz->de.Altura());
}
// Devuelve el elemento TComplejo raíz del árbol AVL 
TComplejo TAVLCom::Raiz() const
{
    if (!this->EsVacio()) return this->raiz->item;
	return TComplejo();
}
// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos) 
int TAVLCom::Nodos() const
{
    if (EsVacio()) return 0;
	return 1 + raiz->de.Nodos() + raiz->iz.Nodos();
}
// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja) 
int TAVLCom::NodosHoja() const
{
    if (EsVacio()) return 0;
    if (!raiz->iz.EsVacio() || !raiz->de.EsVacio()) {
        return raiz->iz.NodosHoja() + raiz->de.NodosHoja();
    } else
        return 1;
}
// Devuelve el recorrido en inorden sobre un vector 
TVectorCom TAVLCom::Inorden() const 
{
    TVectorCom vec(this->Nodos());
    int i = 1;
	this->InordenAux(vec, i);

	return vec;
}
// Devuelve el recorrido en preorden sobre un vector 
TVectorCom TAVLCom::Preorden() const
{
    TVectorCom vec(this->Nodos());
    int i = 1;
    this->PreordenAux(vec, i);
    return vec;
}
// Devuelve el recorrido en postorden sobre un vector 
TVectorCom TAVLCom::Postorden() const
{
    TVectorCom vec(this->Nodos());
    int i = 1;
    this->PostordenAux(vec, i);
    return vec;
}
// Sobrecarga del operador salida
std::ostream & operator<<(std::ostream &os, TAVLCom &avl)
{
    os << avl.Inorden();
    return os;
}
