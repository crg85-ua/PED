#ifndef _TAVLCALENDARIO
#define _TAVLCALENDARIO
#include <ostream>
#include <set>
#include "tcalendario.h"
#include "tvectorcalendario.h"

using namespace std;

class TNodoAVL;

class TAVLCalendario{
    friend class TNodoAVL;
private:

    TNodoAVL *raiz;
    void InordenAux(TVectorCalendario&, int&) const;
    void PreordenAux(TVectorCalendario&, int&) const;
    void PostordenAux(TVectorCalendario&, int&) const;

    TCalendario Maximo() const;

    void RotacionII();
    void RotacionDD();
    void RotacionID();
    void RotacionDI();

public:

    TAVLCalendario();
    TAVLCalendario(TAVLCalendario&);
    ~TAVLCalendario();
    TAVLCalendario& operator=(const TAVLCalendario&);

    bool operator==(TAVLCalendario&);
    bool operator!=(TAVLCalendario&);
    bool EsVacio();
    bool Insertar(TCalendario&);
    bool Buscar(TCalendario&);
    bool Borrar(TCalendario&);
    int Altura();
    int Nodos() const;
    int NodosHoja();
    TVectorCalendario Inorden() const;
    TVectorCalendario Preorden()const;
    TVectorCalendario Postorden() const;
    TCalendario Raiz();

    friend ostream& operator<<(ostream& , TAVLCalendario &);
};


class TNodoAVL{
    friend class TAVLCalendario;
private:

    TCalendario item;
    TAVLCalendario iz;
    TAVLCalendario de;
    int fe;

public:

    TNodoAVL();
    TNodoAVL(TNodoAVL&);
    ~TNodoAVL();
    TNodoAVL& operator=(TNodoAVL&);
};
#endif