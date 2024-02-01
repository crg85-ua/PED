#include "tcalendario.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

    //Constructor por defecto
    TCalendario::TCalendario(){
        dia = 1;
        mes = 1;
        anyo = 1900;
        mensaje = NULL;
    }

    //Constructor con parámetros
    TCalendario::TCalendario(int dia, int mes, int anyo, char * mensaje){
        this->dia = dia;
        this->mes = mes;
        this->anyo = anyo;
        this->mensaje = mensaje;
    }

    //Constructor copia
    TCalendario::TCalendario(const TCalendario& cal){
        this->dia = cal.dia;
        this->mes = cal.mes;
        this->anyo = cal.anyo;
        this->mensaje = cal.mensaje;
        
    }

    //Destructor
    TCalendario::~TCalendario(){
        dia = 1;
        mes = 1;
        anyo = 1900;

        if (mensaje != NULL)
        {
            delete [] mensaje;
            mensaje = NULL;
        }
        
    }