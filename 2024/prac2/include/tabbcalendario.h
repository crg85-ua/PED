#ifndef TABBCALENDARIO_H
#define TABBCALENDARIO_H

#include "tcalendario.h"
#include "tvectorcalendario.h"
#include <queue>

class TNodoABB;

class TABBCalendario {
    friend class TNodoABB;
private:
    TNodoABB *raiz;

    // AUXILIAR: devuelve el recorrido en INORDEN
    void InordenAux( TVectorCalendario &, int &) const;
    // AUXILIAR: devuelve el recorrido en PREORDEN
    void PreordenAux(TVectorCalendario &, int &) const;
    // AUXILIAR: devuelve el recorrido en POSTORDEN
    void PostordenAux(TVectorCalendario &, int &) const;
    TCalendario Maximo() const;
    TCalendario Minimo() const;
public:
    // Constructor
    TABBCalendario();

    // Constructor
    TABBCalendario(const TABBCalendario &);

    // Destructor
    ~TABBCalendario();

    TABBCalendario & operator=(const TABBCalendario &);
    bool operator==(const TABBCalendario &) const;

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

    TABBCalendario operator+(const TABBCalendario &) const;
    TABBCalendario operator-(const TABBCalendario &) const;

};

class TNodoABB {
    friend class TABBCalendario;
private:
    TCalendario item;
    TABBCalendario iz, de;

public:
    // Constructor
    TNodoABB();

    // Constructor
    TNodoABB(const TNodoABB &);

    // Destructor
    ~TNodoABB();

    TNodoABB & operator=(const TNodoABB &);
};

#endif