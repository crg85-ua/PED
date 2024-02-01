#include "tcomplejo.h"
#include <math.h>
#define _USE_MATH_DEFINES
//#include "../include/TComplejo.h"

TComplejo::TComplejo() {
	re = 0;
	im = 0;
}

TComplejo::~TComplejo()
{
    re = 0.0;
    im = 0.0;
}

TComplejo::TComplejo(double re){
    this->re = re;
    this->im = 0;
}

TComplejo::TComplejo(double re, double im){
    this->re = re;
    this->im = im;

}

TComplejo::TComplejo( const TComplejo& numComplejo){
    re = numComplejo.re;
    im = numComplejo.im;
}

TComplejo& TComplejo::operator=( const TComplejo& numComplejo){

    this->~TComplejo();
    
    re = numComplejo.re;
    im = numComplejo.im;
    return *this;
}

//Sobrecarga de operadores aritmeticos

TComplejo TComplejo::operator+(const TComplejo& numComplejo) const{
    TComplejo nuevo;
    nuevo.re = re + numComplejo.re;
    nuevo.im = im + numComplejo.im;
    return nuevo;
}

TComplejo TComplejo::operator-(const TComplejo& numComplejo) const{
    TComplejo nuevo;
    nuevo.re = re - numComplejo.re;
    nuevo.im = im - numComplejo.im;
    return nuevo;
}

TComplejo TComplejo::operator*(const TComplejo& numComplejo) const{
    TComplejo nuevo;
    nuevo.re = re * numComplejo.re;
    if(numComplejo.im != 0)
        nuevo.im = im * numComplejo.im;
    return nuevo;
}

TComplejo TComplejo::operator+(double numReal) const{
    TComplejo real(numReal);
    return this->operator+(real);
}

TComplejo TComplejo::operator-(double numReal) const{
    TComplejo real(numReal);
    return this->operator-(real);
}

TComplejo TComplejo::operator*(double numReal) const{
    TComplejo nuevo;
    if(numReal != 0)
        nuevo.re = re * numReal;
        nuevo.im = im * numReal;
    return nuevo;
}

//Otros operadores
bool TComplejo::operator==(const TComplejo& numComplejo) const{
    double resultRe = re - numComplejo.re;
    double resultIm = im - numComplejo.im;

    if (resultRe == 0.0 && resultIm == 0.0)
    {
        return true;
    }else{
        return false;
    }
       
}

bool TComplejo::operator!=(const TComplejo& numComplejo) const{
    
    double resultRe = re - numComplejo.re;
    double resultIm = im - numComplejo.im;

    if (resultRe != 0.0 || resultIm != 0.0)
    {
        return true;
    }else{
        return false;
    }
}

double TComplejo::Re() const{
    return re;
}
double TComplejo::Im() const{
    return im;
}

void TComplejo::Re(double re) {
    this->re = re;
}

void TComplejo::Im(double im) {
    this->im = im;
}

double TComplejo::Arg(){
    double result = atan2(im,re);
    
    return result;
  
}

double TComplejo::Mod() const{
    double result = sqrt(pow(re,2) + pow(im,2));
    return result;
}

ostream& operator<<(ostream& os, const TComplejo& complejo){
    os<<"("<<complejo.Re()<<" "<<complejo.Im()<<")";
    return os;
}

TComplejo operator+(double re, const TComplejo& complejo){
    TComplejo nuevo = *new TComplejo(re + complejo.Re(), 0+complejo.Im());
    return nuevo;
}

TComplejo operator-(double re, const TComplejo& complejo) { 
    TComplejo nuevo = *new TComplejo(re - complejo.Re(), 0-complejo.Im());
    return nuevo;
}

TComplejo operator*(double re, const TComplejo& complejo) {
    TComplejo nuevo = *new TComplejo(re * complejo.Re(), re*complejo.Im());
    return nuevo;
}

