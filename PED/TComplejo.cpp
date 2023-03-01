#include "TComplejo.h"
//#include "../include/TComplejo.h"

double re;
double im;

TComplejo::TComplejo()
{
    re = 0.0;
    im = 0.0;
}

TComplejo::~TComplejo()
{
    re = 0.0;
    im = 0.0;
}


TComplejo::TComplejo(double re)
{
    this->re = re;
}

TComplejo::TComplejo(double re , double im){
    this->re = re;
    this->im = im;

}

TComplejo::TComplejo(TComplejo& numComplejo){
    re = numComplejo.re;
    im = numComplejo.im;
}

