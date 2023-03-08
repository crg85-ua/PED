
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
    //this->c.size = vectorCom.size;

}