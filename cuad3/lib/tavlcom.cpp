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
    this->raiz = arbol.raiz;
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

bool TAVLCom::EsVacio()
{
    if (raiz)
    {
        return false;
    }

    return true;
}

bool TAVLCom::Insertar(TComplejo &nodo)
{
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
    bool removed;
    if (this->Buscar(nodo))
    {
        if (this->raiz->item == nodo) {
            if (this->raiz->de.EsVacio() && this->raiz->iz.EsVacio()) {
                delete this->raiz;
                this->raiz = NULL;

                return true;
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
        }
    }
    
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

TComplejo TAVLCom::mayorIzquierda(TNodoAVL* nodo) {
    if (nodo == NULL)
        return TComplejo();

    while (nodo->de.raiz != NULL)
        nodo = nodo->de.raiz;

    return nodo->item;
}

void TAVLCom::sustituir(TNodoAVL* &nodo, const TComplejo &valor) {
    if (nodo == NULL)
        return;

    if (valor.Mod() > nodo->item.Mod())
        sustituir(nodo->de.raiz, valor);
    else if (valor.Mod() < nodo->item.Mod())
        sustituir(nodo->iz.raiz, valor);
    else {
        if (nodo->iz.raiz != NULL && nodo->de.raiz != NULL) {
            TComplejo mayor = mayorIzquierda(nodo->iz.raiz);
            nodo->item = mayor;
            sustituir(nodo->iz.raiz, mayor);
        } else {
            TNodoAVL* eliminar = nodo;
            nodo = (nodo->iz.raiz != NULL) ? nodo->iz.raiz : nodo->de.raiz;
            delete eliminar;
        }
    }
}

ostream &operator<<(ostream &os, TAVLCom &arbol)
{
    return os << arbol.Inorden();
}
