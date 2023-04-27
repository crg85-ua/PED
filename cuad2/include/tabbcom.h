#ifndef _TABB_H_
#define _TABB_H_
#include <iostream>
#include "tcomplejo.h"
#include "tvectorcom.h"
#include <vector>


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
        bool operator==(const TNodoABB&);
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
        bool EsVacio();
        bool Insertar(TComplejo&);
        bool Borrar(TComplejo&);
        bool Buscar(TComplejo&);
        TComplejo Raiz();
        int Altura();
        int Nodos();
        int NodosHoja();
        TVectorCom Inorden();
        TVectorCom Preorden();
        TVectorCom Postorden();
        TVectorCom Niveles();

        friend ostream & operator<<(ostream&, TABBCom&);

        friend class TNodoABB;
};
#endif