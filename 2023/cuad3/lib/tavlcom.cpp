#include "tavlcom.h"

TNodoAVL::TNodoAVL()
{
    this->fe = 0;
}

TNodoAVL::TNodoAVL(TNodoAVL &nodo)
{
    *this = nodo;
}

TNodoAVL::~TNodoAVL()
{
    this->fe = 0;
}

TNodoAVL &TNodoAVL::operator=(TNodoAVL &nodo)
{
    if (this != &nodo)
    {
        this->item = nodo.item;
        this->iz = nodo.iz;
        this->de = nodo.de;
        this->fe = nodo.fe;
    }

    return *this;
}

/// TAVLCom
/// PRIVATE
void TAVLCom::InordenAux(TVectorCom &vector, int &num)
{
    if (!this->EsVacio())
    {
        if (this->raiz->iz.EsVacio() && this->raiz->de.EsVacio())
        {
            vector[num] = this->raiz->item;
            num++;
        }
        else
        {
            this->raiz->iz.PreordenAux(vector, num);
            this->raiz->de.PreordenAux(vector, num);
            vector[num] = this->raiz->item;
            num++;
        }
    }
}

void TAVLCom::PreordenAux(TVectorCom &vector, int &num)
{
    if (!this->EsVacio())
    {
        if (this->raiz->iz.EsVacio() && this->raiz->de.EsVacio())
        {
            vector[num] = this->raiz->item;
            num++;
        }
        else
        {
            vector[num] = this->raiz->item;
            num++;
            this->raiz->iz.PreordenAux(vector, num);
            this->raiz->de.PreordenAux(vector, num);
        }
    }
}

void TAVLCom::PostordenAux(TVectorCom &vector, int &num)
{
    if (!this->EsVacio())
    {
        if (this->raiz->iz.EsVacio() && this->raiz->de.EsVacio())
        {
            vector[num] = this->raiz->item;
            num++;
        }
        else
        {
            this->raiz->iz.PreordenAux(vector, num);
            this->raiz->de.PreordenAux(vector, num);
            vector[num] = this->raiz->item;
            num++;
        }
    }
}

/// PUBLIC
TAVLCom::TAVLCom()
{
    this->raiz = NULL;
}

TAVLCom::TAVLCom(const TAVLCom &arbol)
{
    if (!arbol.EsVacio()) {
        Copia(arbol);
	} else
		this->raiz = NULL;
}

TAVLCom::~TAVLCom()
{
    //this->raiz = new TNodoAVL();
}

TAVLCom &TAVLCom::operator=(const TAVLCom &arbol)
{
    if (this->raiz != arbol.raiz)
    {
        this->raiz = arbol.raiz;
    }
    return *this;
}

bool TAVLCom::operator==(TAVLCom &arbol)
{
    return (this->Inorden() == arbol.Inorden());
}

bool TAVLCom::operator!=(TAVLCom &arbol)
{
    return (this->Inorden() != arbol.Inorden());
}

bool TAVLCom::EsVacio() const
{
    if (raiz)
    {
        return false;
    }

    return true;
}

bool TAVLCom::Insertar(TComplejo &nodo)
{
    bool result = false;
    if (this->Buscar(nodo))
    {
        return false;
    }
    
    if (this->EsVacio()) {
        this->raiz = new TNodoAVL();
        this->raiz->item = nodo;
        result = true;
    } else if (mayorQue(this->raiz->item,nodo)) {
        result = this->raiz->iz.Insertar(nodo);
    } else {
        result = this->raiz->de.Insertar(nodo);
    }

    // Actualizar factor de equilibrio del nodo
    this->raiz->fe = this->raiz->de.Altura() - this->raiz->iz.Altura();

    if (this->raiz->fe < -1 || this->raiz->fe > 1) {
        if (this->raiz->fe < -1) {
            if (mayorQue(nodo,this->raiz->iz.raiz->item)) {
                // Rotación doble izquierda-derecha
                RotacionIzquierda(this->raiz->iz.raiz);
            }
            // Rotación simple derecha
            RotacionDerecha(this->raiz);
        } else if (this->raiz->fe > 1) {
            if (mayorQue(this->raiz->de.raiz->item,nodo)) {
                // Rotación doble derecha-izquierda
                RotacionDerecha(this->raiz->de.raiz);
            }
            // Rotación simple izquierda
            RotacionIzquierda(this->raiz);
        }
    }
    return result;
}

bool TAVLCom::mayorQue(const TComplejo& existe, const TComplejo& nuevo){
    return (existe.Mod() > nuevo.Mod()) ||
            (existe.Re() > nuevo.Re()) || 
            (existe.Re() == nuevo.Re() && 
            existe.Im() > nuevo.Im());
}

bool TAVLCom::Buscar(const TComplejo &nodo)
{

    if (!EsVacio())
    {
        if (this->raiz->item == nodo)
        {
            return true;
        }
        else
        {
            if (this->raiz->iz.Buscar(nodo) ||
                this->raiz->de.Buscar(nodo))
            {
                return true;
            }
        }
    }

    return false;
}

bool TAVLCom::Borrar(TComplejo &nodo)
{
    bool eliminado = false;
    if (this->Buscar(nodo))
    {
        if (this->raiz->item == nodo) {
            //Si es una hoja 
            if (this->raiz->de.EsVacio() && this->raiz->iz.EsVacio()) {
                delete this->raiz;
                this->raiz = NULL;

                return true;
            //Si solo tiene un hijo
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
                return true;
            //Si tiene 2 hijos, por tanto es el nodo de un arbol
            } else {
                sustituir(nodo);
                return true;
            }
        }else {
            if (mayorQue(raiz->item, nodo)) {
                eliminado = this->raiz->iz.Borrar(nodo);
            } else {
                eliminado = this->raiz->de.Borrar(nodo);
            }
        }
    }
    
    return eliminado;
}

int TAVLCom::Altura()
{
    if (this->EsVacio())
    {
        return 0;
    }
    else
    {
        return 1 + max(this->raiz->iz.Altura(), this->raiz->de.Altura());
    }
}

TComplejo TAVLCom::Raiz()
{
    if (EsVacio())
    {
        return TComplejo();
    }
    else
    {
        return this->raiz->item;
    }
}

int TAVLCom::Nodos()
{
    if (this->EsVacio())
    {
        return 0;
    }
    else
    {
        return 1 + this->raiz->iz.Nodos() + this->raiz->de.Nodos();
    }
}

int TAVLCom::NodosHoja()
{
    if (!EsVacio())
    {
        if (raiz->iz.EsVacio() && raiz->de.EsVacio())
        {
            return 1;
        }
        else
        {
            return raiz->iz.NodosHoja() + raiz->de.NodosHoja();
        }
    }
    else
    {
        return 0;
    }
}

TVectorCom TAVLCom::Inorden()
{
    int pos = 1;

    TVectorCom v(Nodos());
    InordenAux(v, pos);
    return v;
}

TVectorCom TAVLCom::Preorden()
{
    int pos = 1;

    TVectorCom v(Nodos());
    PreordenAux(v, pos);
    return v;
}

TVectorCom TAVLCom::Postorden()
{
    int pos = 1;

    TVectorCom v(Nodos());
    PostordenAux(v, pos);
    return v;
}

TComplejo TAVLCom::mayorIzquierda(TNodoAVL* &nodo) {
    if (nodo == NULL)
        return TComplejo();

    while (nodo->de.raiz != NULL)
        nodo = nodo->de.raiz;

    return nodo->item;
}

void TAVLCom::sustituir(const TComplejo &valor) {
    if (this == NULL)
        return;

    if (mayorQue(valor,this->raiz->item))
        this->raiz->iz.sustituir(valor);
    else if (mayorQue(this->raiz->item,valor))
        this->raiz->de.sustituir(valor);
    else {
        if (this->raiz->iz.raiz != NULL && this->raiz->de.raiz != NULL) {
            TComplejo mayor = mayorIzquierda(this->raiz->iz.raiz);
            this->raiz->item = mayor;
            this->raiz->iz.sustituir(mayor);
        } else {
            TNodoAVL* eliminar = this->raiz;
            this->raiz = (this->raiz->iz.raiz != NULL) ? this->raiz->iz.raiz : this->raiz->de.raiz;
            delete eliminar;
        }
    }
}

void TAVLCom::RotacionDerecha( TNodoAVL* &nodo) {
    TNodoAVL* aux = nodo->iz.raiz;
    nodo->iz.raiz = aux->de.raiz;
    aux->de.raiz = nodo;
    nodo = aux;

    // Actualizar factores de equilibrio
    nodo->de.raiz->fe = nodo->de.Altura() - nodo->iz.Altura();
    nodo->fe = nodo->de.Altura() - nodo->iz.Altura();
}

void TAVLCom::RotacionIzquierda(TNodoAVL* &nodo) {
    TNodoAVL* aux = nodo->de.raiz;
    nodo->de.raiz = aux->iz.raiz;
    aux->iz.raiz = nodo;
    nodo = aux;

    // Actualizar factores de equilibrio
    nodo->iz.raiz->fe = nodo->de.Altura() - nodo->iz.Altura();
    nodo->fe = nodo->de.Altura() - nodo->iz.Altura();
}

TAVLCom& TAVLCom::Copia(const TAVLCom& arbol){
    if (!arbol.EsVacio())
    {
        this->raiz = new TNodoAVL();
		this->raiz->item = arbol.raiz->item;
		this->raiz->iz.Copia(arbol.raiz->iz);
		this->raiz->de.Copia(arbol.raiz->de);
    } else {
        this->raiz = NULL;
    }
    return *this;
}

ostream &operator<<(ostream &os, TAVLCom &arbol)
{
    return os << arbol.Inorden();
}
