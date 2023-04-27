
#include "../include/tcomplejo.h"
#include "../include/tvectorcom.h"

TVectorCom::TVectorCom() : error(){
    c = new TComplejo();
    tamano = 0;
}

TVectorCom::TVectorCom(int tamano) : error(){   
    c = new TComplejo[tamano];
    this->tamano = tamano;
}

TVectorCom::TVectorCom(TVectorCom& vectorCom) : error(){
    this->tamano = vectorCom.tamano;
    this->c = new TComplejo[vectorCom.tamano];

    for (int i = 0; i < tamano; i++)
    {
        c[i] = vectorCom.c[i];
    }
    
}

TVectorCom::~TVectorCom(){
    c = new TComplejo();
    tamano = 0;
}

TVectorCom& TVectorCom::operator=(const TVectorCom& vectorCom) {
   
    this->tamano = vectorCom.tamano;
    this->c = new TComplejo[vectorCom.tamano];

    for (int i = 0; i < tamano; i++)
    {
        c[i] = vectorCom.c[i];
    }

    return *this;
}

bool TVectorCom::operator==(const TVectorCom& vectorCom) const{
    bool result = true;
    if (this->tamano == vectorCom.tamano){
        for(int i = 0; i < tamano; i++){
            if(this->c [i] != vectorCom.c[i]){
                result = false;
                return result;
            }
        }
    }else{
        return false;    

    }

    return result;
}

bool TVectorCom::operator!=(const TVectorCom& vectorCom) const {
	return !(*this == vectorCom);
}


TComplejo& TVectorCom::operator[](int pos){
    
    if(pos>=1 && pos <= tamano){
        return this->c[pos-1];    
    }
    return error;
    
}

TComplejo TVectorCom::operator[](int pos) const{
  
    if(pos>=1 && pos <= tamano){
        return this->c[pos-1];    
    }else{
        return TComplejo();
    }
}

int TVectorCom::Tamano(){
    return tamano;
}

int TVectorCom::Ocupadas(){
    int cantidadOcupadas = 0;

    for (int i = 0; i < this->tamano; i++)
    {
        if(this->c[i].Re() != 0 || this->c[i].Im() != 0){
            cantidadOcupadas++;
        }
    }

    return cantidadOcupadas;
}

bool TVectorCom::ExisteCom(const TComplejo& complejo) const{
    bool result = false;
    for(int i = 0; i < tamano; i++){
        if(this->c[i] == complejo){
            result = true;
        }      
    }
    return result;
}

void TVectorCom::MostrarComplejos(double arg){
    TComplejo complejo;
    cout << "[";
    for(int i = 0; i < tamano; i++){
        complejo = this->c[i];

        if(complejo.Re() >= arg){
            cout << this->c[i];
            if (i != tamano-2)
                cout << ", ";
            
        }
       
    }
    cout << "]";
}

bool TVectorCom::Redimensionar(int nuevoTamano){
    if(nuevoTamano == 0 || nuevoTamano < 0){
        return false;
    } else if(nuevoTamano == tamano){
        return false;
    } else if(nuevoTamano > 0 && nuevoTamano > tamano){
        TComplejo* nuevoPuntero = new TComplejo[nuevoTamano];
        for (int i = 0; i < tamano; i++)
        {         
            nuevoPuntero[i] = c[i];          
            
        }
        c = nuevoPuntero;
        tamano = nuevoTamano;
        
        return true;

    } else if (nuevoTamano > 0 && nuevoTamano <tamano)
    {
        TComplejo* nuevoPuntero = new TComplejo[nuevoTamano];
        for (int i = 0; i < nuevoTamano; i++)
        {
            nuevoPuntero[i] = c[i];
        }
        c = nuevoPuntero;
        tamano = nuevoTamano;

        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const TVectorCom& vector){
    os << "[" ;
    if (vector.tamano == 0)
    {
        os << "]";
    } else
    {
        for (int i = 0; i < vector.tamano; i++)
        {
            os << "(" << i + 1 << ") " << vector.c[i];
            if (i != vector.tamano-1)
                os << ", ";
        }
        os << "]";
    }  
    return os;
    
}