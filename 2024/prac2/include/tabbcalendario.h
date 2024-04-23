#ifndef TABBCALENDARIO_H
#define TABBCALENDARIO_H

#include "tcalendario.h"
#include "tvectorcalendario.h"

class TNodoABB;

class TABBCalendario {
private:
    TNodoABB *raiz;

    // AUXILIAR: devuelve el recorrido en INORDEN
    void InordenAux(TVectorCalendario &, int &);
    // AUXILIAR: devuelve el recorrido en PREORDEN
    void PreordenAux(TVectorCalendario &, int &);
    // AUXILIAR: devuelve el recorrido en POSTORDEN
    void PostordenAux(TVectorCalendario &, int &);
public:
    // Constructor
    TABBCalendario();

    // Constructor
    TABBCalendario(TABBCalendario &);

    // Destructor
    ~TABBCalendario();

    TABBCalendario & operator=(const TABBCalendario &);


    //Métodos
    bool EsVacio() const;
    bool Insertar(const TCalendario &);
    bool Borrar(const TCalendario &);
    bool Buscar(const TCalendario &) const;
    TCalendario Raiz() const;
    int Altura() const;
    int Nodos() const;
    int NodosHoja() const;
    TVectorCalendario Inorden() const;
    TVectorCalendario Preorden() const;
    TVectorCalendario Postorden() const;
    TVectorCalendario Niveles() const;

    friend ostream & operator<<(ostream &, const TABBCalendario &);

    TABBCalendario operator+(const TABBCalendario &);
    TABBCalendario operator-(const TABBCalendario &);

};

class TNodoABB {
private:
    TCalendario item;
    TABBCalendario iz, de;

public:
    // Constructor
    TNodoABB();

    // Constructor
    TNodoABB(TNodoABB &);

    // Destructor
    ~TNodoABB();

    TNodoABB & operator=(const TNodoABB &);
};

#endif