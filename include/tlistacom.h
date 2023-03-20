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
        
        bool operator!=(TListaNodo&);
};

class TListaPos{
    private:
        TListaNodo *pos;
    public: 
        TListaPos();

        TListaPos(TListaPos&);

        ~TListaPos();

        TListaPos& operator=(TListaPos&);

        bool operator==(TListaPos&);

        bool operator!=(TListaPos&);

        TListaPos Anterior();

        TListaPos Siguiente();

        bool EsVacia();

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


};

#endif