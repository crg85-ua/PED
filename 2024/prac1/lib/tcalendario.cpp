#include "tcalendario.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

    bool TCalendario::esBisiesto( int anyo){
        return (anyo % 4 == 0 && anyo % 100 != 0) || (anyo % 400 == 0);
    }

    bool TCalendario::fechaCorrecta(int dia, int mes, int anyo){

        bool correct = true;
        set<int> meses31 = {1,3,5,7,8,10,12};

        if (anyo < 1900)
        {
            correct = false;
        } else{
            if (mes <= 12)
            {
                if (meses31.count(mes) > 0)
                {
                    correct = (dia <= 31);              
                    
                    
                } else if (mes == 2){
                    //Si el año es bisiesto
                    correct = (esBisiesto(anyo) ? dia <= 29 : dia <= 28);
                    
                }else{
                    correct = (dia <= 30);                
                }
            }
            
        }
        return correct;
    }


    //Constructor por defecto
    TCalendario::TCalendario(){
        dia = 1;
        mes = 1;
        anyo = 1900;
        mensaje = NULL;
    }

    //Constructor con parámetros
    TCalendario::TCalendario(int dia, int mes, int anyo, char * mensaje){
        bool correct = fechaCorrecta(dia, mes, anyo);

        if (!correct)
        {
            this->dia = 1;
            this->mes = 1;
            this->anyo = 1900;
            this->mensaje = NULL;
        }else{
            this->dia = dia;
            this->mes = mes;
            this->anyo = anyo;
            this->mensaje = mensaje;
        }
                
    }

    //Constructor copia
    TCalendario::TCalendario(const TCalendario& cal){

        if (fechaCorrecta(cal.dia, cal.mes,cal.anyo))
        {
            this->dia = cal.dia;
            this->mes = cal.mes;
            this->anyo = cal.anyo;
            if (mensaje != NULL){
                delete [] this->mensaje;
            }
            this->mensaje = cal.mensaje;
        }else{
            this->dia = 1;
            this->mes = 1;
            this->anyo = 1900;
            this->mensaje = NULL;
        }
        
        
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

    TCalendario& TCalendario::operator=(const TCalendario& cal){
        TCalendario error;

        if (fechaCorrecta(cal.dia, cal.mes, cal.anyo))
        {
            this->dia = cal.dia;
            this->mes = cal.mes;
            this->anyo = cal.anyo;
            if (mensaje != NULL){
                delete [] this->mensaje;
            }
            this->mensaje = cal.mensaje;

            return (*this);
        }
        
        return error;        
    }

    TCalendario TCalendario::operator+(const TCalendario&){
        
    }