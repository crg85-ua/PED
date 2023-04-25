#ifndef _TLISTA_H_
#define _TLISTA_H_
#include <iostream>
#include "tcomplejo.h"
#include <vector>


using namespace std;

class TListaNodo{

    private:
        TComplejo e;
        TListaNodo *anterior;
        TListaNodo *siguiente;
    
    public:
        TListaNodo();

        TListaNodo(TListaNodo&);

        ~TListaNodo();

        TListaNodo& operator=(TListaNodo&);

        TComplejo& GetComplejo();

        TListaNodo* GetAnterior();

        TListaNodo* GetSiguiente();

        friend class TListaPos;
        friend class TListaCom;
        
};

class TListaPos{

    private:
        TListaNodo *pos;
    public: 
        TListaPos();

        TListaPos(TListaPos&);

        ~TListaPos();

        TListaPos& operator=(const TListaPos&);

        bool operator==(const TListaPos&);

        bool operator!=(const TListaPos&);

        TListaPos Anterior() const;

        TListaPos Siguiente() const;

        bool EsVacia() const;

        friend class TListaNodo;

        friend class TListaCom;

};

class TListaCom{
    private:
        TListaNodo *primero;
        TListaNodo *ultimo;
    public:
        TListaCom();

        TListaCom(TListaCom&);

        ~TListaCom();

        TListaCom& operator=(TListaCom&);

        bool operator==(TListaCom&);

        bool operator!=(TListaCom&);

        TListaCom operator+(TListaCom&);

        TListaCom operator-(TListaCom&);

        bool EsVacia();

        bool InsCabeza(TComplejo&);

        bool InsertarI(TComplejo&, TListaPos&);

        bool InsertarD(TComplejo&, TListaPos&);

        bool Borrar(TComplejo&);

        bool BorrarTodos(TComplejo&);

        bool Borrar(TListaPos&);

        TComplejo Obtener(TListaPos&);

        bool Buscar(TComplejo&);

        int Longitud();

        TListaPos Primera();

        TListaPos Ultima();

        friend ostream& operator<<(ostream&, TListaCom&);

        friend class TListaNodo;

        friend class TListaPos;


};

#endif