#ifndef _TAVL_H_
#define _TAVL_H_

#include <iostream>
#include "tcomplejo.h"
#include "tvectorcom.h"
#include <vector>
#include <queue>

using namespace std;

class TNodoAVL;

class TAVLCom
{
    private:
        TNodoAVL *raiz;
        void InordenAux(TVectorCom&, int&);
        void PreordenAux(TVectorCom&, int&);
        void PostordenAux(TVectorCom&, int&);
    public:
        TAVLCom();
        TAVLCom(const TAVLCom&);
        ~TAVLCom();
        TAVLCom& operator=(const TAVLCom&);

        bool operator==(TAVLCom&);
        bool operator!=(TAVLCom&);
        bool EsVacio();
        bool Insertar(TComplejo&);
        bool Buscar(const TComplejo&);
        bool Borrar(TComplejo&);
        int Altura();
        TComplejo Raiz();
        int Nodos();
        int NodosHoja();
        TVectorCom Inorden();
        TVectorCom Preorden();
        TVectorCom Postorden();
        TComplejo mayorIzquierda(TNodoAVL*);
        void sustituir(TNodoAVL*&, const TComplejo&);

        friend ostream& operator<<(ostream&, TAVLCom&);

        friend class TNodoAVL;
    

};

class TNodoAVL
{
    private:
        TComplejo item;
        TAVLCom iz;
        TAVLCom de;
        int fe;
    public:
        TNodoAVL();
        TNodoAVL(TNodoAVL&);
        ~TNodoAVL();
        TNodoAVL& operator=(TNodoAVL&);
        
        friend class TAVLCom;
};

#endif