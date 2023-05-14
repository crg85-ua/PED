#ifndef _TVECTOR_H_
#define _TVECTOR_H_
#include<iostream>
#include "tcomplejo.h"
#include <vector>

using namespace std;

class TVectorCom : public vector<TComplejo>{
    private:
        TComplejo* c;
        int tamano;
        TComplejo error;
    public:
        TVectorCom();

        TVectorCom(int);

        TVectorCom(TVectorCom&);

        ~TVectorCom();

        TVectorCom& operator=(const TVectorCom&);

        bool operator==(const TVectorCom&) const;

        bool operator!=(const TVectorCom&) const;

        TComplejo& operator[](int);

        TComplejo operator[](int) const;

        int Tamano();

        int Ocupadas();

        bool ExisteCom(const TComplejo&) const;

        void MostrarComplejos(double);
        
        bool Redimensionar(int);

        friend ostream& operator<<(ostream&, const TVectorCom&);
};
#endif