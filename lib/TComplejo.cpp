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

TComplejo& TComplejo::operator=(TComplejo& numComplejo){
    this->re = numComplejo.re;
    this->im = numComplejo.im;
    return *this;
}

//Sobrecarga de operadores aritmeticos

TComplejo TComplejo::operator+(TComplejo& numComplejo){
    re = re + numComplejo.re;
    im = im + numComplejo.im;
    return *this;
}

TComplejo TComplejo::operator-(TComplejo& numComplejo){
    re = re - numComplejo.re;
    im = im - numComplejo.im;
    return *this;
}

TComplejo TComplejo::operator*(TComplejo& numComplejo){
    re = re * numComplejo.re;
    im = im * numComplejo.im;
    return *this;
}

TComplejo TComplejo::operator+(double numReal){
    re = re + numReal;
    return *this;
}

TComplejo TComplejo::operator-(double numReal){
    re = re - numReal;
    return *this;
}

TComplejo TComplejo::operator*(double numReal){
    re = re * numReal;
    return *this;
}

//Otros operadores
bool TComplejo::operator==(TComplejo& numComplejo){
    double resultRe = re - numComplejo.re;
    double resultIm = im - numComplejo.im;

    if (resultRe == 0.0 && resultIm == 0.0)
    {
        return true;
    }else{
        return false;
    }
       
}

bool TComplejo::operator!=(TComplejo& numComplejo){
    
    double resultRe = re - numComplejo.re;
    double resultIm = im - numComplejo.im;

    if (resultRe != 0.0 || resultIm != 0.0)
    {
        return true;
    }else{
        return false;
    }
}

double TComplejo::Re(){
    return re;
}
double TComplejo::Im(){
    return im;
}

void TComplejo::Re(double re){
    this->re = re;
}

void TComplejo::Im(double im){
    this->im = im;
}

double TComplejo::Arg(){
    double result; 

    if(re == 0.0 && im == 0.0){
        result = 0.0;
    }else if( re == 0.0 && im > 0.0){
    //result = pi()/2;
    }else if( re == 0.0 && im < 0.0){
    //result = 3*pi()/2;
    }else{
    result = atan2(im,re);
    }
    return result;
  
}

double TComplejo::Mod(){

}
