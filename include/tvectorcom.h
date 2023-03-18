#ifndef _TVECTOR_H_
#define _TVECTOR_H_
#include<iostream>
#include "tcomplejo.h"
#include <vector>

using namespace std;

class TVectorCom : public vector<TComplejo>{
    private:
        TComplejo* c;
        int tamaño;
    public:
        TVectorCom();

        TVectorCom(int);

        TVectorCom(TVectorCom&);

        ~TVectorCom();

        TVectorCom& operator=(TVectorCom&);

        bool operator==(TVectorCom&);

        bool operator!=(TVectorCom&);

        TComplejo& operator[](int);

        TComplejo operator[](int) const;

        int Tamaño();

        int Ocupadas();

        bool ExisteCom(TComplejo&);

        void MostrarComplejos(double);
        
        bool Redimensionar(int);

        friend ostream& operator<<(ostream&, TVectorCom&);
};
#endif