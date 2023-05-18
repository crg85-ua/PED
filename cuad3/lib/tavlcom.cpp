#include "tavlcom.h"

TNodoAVL::TNodoAVL()
{
    this->item = TComplejo();
    this->iz = TAVLCom();
    this->de = TAVLCom();
    this->fe = 0;
}

TNodoAVL::TNodoAVL(TNodoAVL &nodo)
{
    *this = nodo;
}

TNodoAVL::~TNodoAVL()
{
    this->item = TComplejo();
    this->iz = TAVLCom();
    this->de = TAVLCom();
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

TAVLCom::TAVLCom()
{
    this->raiz = new TNodoAVL();
}

TAVLCom::TAVLCom(const TAVLCom &arbol)
{
    this->raiz = arbol.raiz;
}

TAVLCom::~TAVLCom()
{
    this->raiz = new TNodoAVL();
}

TAVLCom &TAVLCom::operator=(TAVLCom &arbol)
{
    if (this->raiz != arbol.raiz)
    {
        this->raiz = arbol.raiz;
    }
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

bool TAVLCom::Buscar(TComplejo &nodo)
{
}

bool TAVLCom::Borrar(TComplejo &nodo)
{
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
}

TVectorCom TAVLCom::Preorden()
{
}

TVectorCom TAVLCom::Postorden()
{
}

ostream &operator<<(ostream &os, TAVLCom &arbol)
{
}
