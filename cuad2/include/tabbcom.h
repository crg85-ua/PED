#ifndef _TABB_H_
#define _TABB_H_
#include <iostream>
#include "tcomplejo.h"
#include "tvectorcom.h"
#include <vector>
#include <queue>

using namespace std;

class TNodoABB{
    private:
        TComplejo item;
        TABBCom iz, de;
    public:
        TNodoABB();
        TNodoABB(TNodoABB&);
        ~TNodoABB();
        TNodoABB& operator=(TNodoABB&);
        friend class TABBCom;

};

class TABBCom{
    private:
        TNodoABB *nodo;
        void InordenAux(TVectorCom&, int&);
        void PreordenAux(TVectorCom&, int&);
        void PostordenAux(TVectorCom&, int&);
    public:

        TABBCom();
        TABBCom(TABBCom&);
        ~TABBCom();
        TABBCom& operator=(TABBCom&);
        bool operator==(const TABBCom&);
        bool EsVacio() const;
        bool Insertar(const TComplejo&);
        bool Borrar(const TComplejo&);
        bool Buscar(const TComplejo&);
        TComplejo Raiz();
        int Altura();
        int Nodos();
        int NodosHoja();
        TVectorCom Inorden();
        TVectorCom Preorden();
        TVectorCom Postorden();
        TVectorCom Niveles();
        TABBCom& Copia(const TABBCom&);
        TNodoABB* BuscarMaximo(TABBCom arbol);
        friend ostream & operator<<(ostream&, TABBCom&);

        friend class TNodoABB;
};
#endif