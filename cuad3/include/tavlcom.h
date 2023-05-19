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
        bool EsVacio() const;
        bool Insertar(TComplejo&);
        bool Buscar(const TComplejo&);
        bool Borrar(TComplejo&);
        TAVLCom& Copia(const TAVLCom&);
        int Altura();
        TComplejo Raiz();
        int Nodos();
        int NodosHoja();
        TVectorCom Inorden();
        TVectorCom Preorden();
        TVectorCom Postorden();
        TComplejo mayorIzquierda(TNodoAVL*&);
        void sustituir(const TComplejo&);
        bool mayorQue(const TComplejo&, const TComplejo&);
        void RotacionDerecha(TNodoAVL* &);
        void RotacionIzquierda(TNodoAVL* &);

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