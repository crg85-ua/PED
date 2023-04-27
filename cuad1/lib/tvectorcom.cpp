
#include "tcomplejo.h"
#include "tvectorcom.h"

TVectorCom::TVectorCom() : error(){
    c = new TComplejo();
    tamano = 0;
}

TVectorCom::TVectorCom(int tamano) : error(){
    c = new TComplejo();
    this->tamano = tamano;
}

TVectorCom::TVectorCom(TVectorCom& vectorCom) : error(){
    this->tamano = vectorCom.tamano;
    this->c = vectorCom.c;
}

TVectorCom::~TVectorCom(){
    c = new TComplejo();
    tamano = 0;
}

TVectorCom& TVectorCom::operator=(TVectorCom& vectorCom){
    this->c = vectorCom.c;
    this->tamano = vectorCom.tamano;

    return *this;
}

bool TVectorCom::operator==(TVectorCom& vectorCom){
    bool result = true;
    if (this->tamano == vectorCom.Tamano()){
        for(int i = 0; i < tamano; i++){
            if(*(this->c + i) != *(vectorCom.c + i)){
                result = false;
                return result;
            }
        }
    }else{
        return false;    

    }

    return result;
}

TComplejo& TVectorCom::operator[](int pos){
    
    if(pos>=1 && pos <= tamano){
        return *(this->c +(pos -1));    
    }
    return error;
    
}

TComplejo TVectorCom::operator[](int pos) const{
  
    if(pos>=1 && pos <= tamano){
        return *(this->c +(pos -1));    
    }else{
        return TComplejo();
    }
}

int TVectorCom::Tamano(){
    return tamano;
}

int TVectorCom::Ocupadas(){
    int cantidadOcupadas = 0;
    TComplejo complejo;
    for (int i = 0; i > tamano; i++)
    {
        complejo = *(this->c + i);
        if(complejo.Im() != 0 && complejo.Re() != 0){
            cantidadOcupadas++;
        }
    }
    return cantidadOcupadas;
}

bool TVectorCom::ExisteCom(TComplejo& complejo){
    bool result = false;
    for(int i = 0; i < tamano; i++){
        result = *(this->c + i) != complejo;
        if(result){
            return result;
        }
       
    }
    return result;
}

void TVectorCom::MostrarComplejos(double arg){
    TComplejo complejo;
    cout << "[ ";
    for(int i = 0; i < tamano; i++){
        complejo = *(this->c + i);

        if(complejo.Re() > arg || complejo.Re() == arg){
            cout << *(this->c + i) << ", ";
        }
       
    }
    cout << " ]" << endl;
}

bool TVectorCom::Redimensionar(int nuevoTamano){
    if(nuevoTamano == 0 || nuevoTamano < 0){
        return false;
    } else if(nuevoTamano == tamano){
        return false;
    } else if(nuevoTamano > 0 && nuevoTamano > tamano){
        
        for (int i = 0; i < nuevoTamano; i++)
        {
            if (i > tamano -1)
            {
                TComplejo complejo = TComplejo();
                *(c+i) = complejo;
            }
            
        }
        tamano = nuevoTamano;
        
        return true;

    } else if (nuevoTamano > 0 && nuevoTamano <tamano)
    {
        TComplejo* nuevoPuntero;
        for (int i = 0; i < nuevoTamano; i++)
        {
            *(nuevoPuntero+i) = *(c+i);
        }
        c = nuevoPuntero;
        tamano = nuevoTamano;

        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, TVectorCom& vector){
    os << "[" ;
    if (vector.Tamano() == 0)
    {
        os << "]";
    } else
    {
        for (int i = 1; i = vector.Tamano(); i++)
        {
            os << "(" << i << ") " << *(vector.c + (i-1)) << ", ";
        }
    }  
    return os;
    
}