
#include "TComplejo.h"
#include "TVectorCom.h"

TVectorCom::TVectorCom(){
    c = new TComplejo();
    tamaño = 0;
}

TVectorCom::TVectorCom(int tamaño){
    c = new TComplejo();
    this->tamaño = tamaño;
}

TVectorCom::TVectorCom(TVectorCom& vectorCom){
    this->tamaño = vectorCom.tamaño;
    this->c = vectorCom.c;
}

TVectorCom::~TVectorCom(){
    c = new TComplejo();
    tamaño = 0;
}

TVectorCom& TVectorCom::operator=(TVectorCom& vectorCom){
    this->c = vectorCom.c;
    this->tamaño = vectorCom.tamaño;

    return *this;
}

bool TVectorCom::operator==(TVectorCom& vectorCom){
    bool result = true;
    if (this->tamaño == vectorCom.Tamaño()){
        for(int i = 0; i < tamaño; i++){
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
    if(pos>=1 && pos <= tamaño){
        return *(this->c +(pos -1));    
    }
}

TComplejo TVectorCom::operator[](int pos) const{
  
    if(pos>=1 && pos <= tamaño){
        return *(this->c +(pos -1));    
    }else{
        return TComplejo();
    }
}

int TVectorCom::Tamaño(){
    return tamaño;
}

int TVectorCom::Ocupadas(){
    int cantidadOcupadas = 0;
    
    for (int i = 0; i > tamaño; i++)
    {
        if((c+i)->Im() != 0 && (c+i)->Re() != 0){
            cantidadOcupadas++;
        }
    }
    return cantidadOcupadas;
}

bool TVectorCom::ExisteCom(TComplejo& complejo){
    bool result = false;
    for(int i = 0; i < tamaño; i++){
        result = *(this->c + i) != complejo;
        if(result){
            return result;
        }
       
    }
    return result;
}

void TVectorCom::MostrarComplejos(double arg){
    
}