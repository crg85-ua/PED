#include "tcalendario.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

    const int DIAS_EN_MES[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Días en cada mes (enero a diciembre)

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
            if(mensaje != NULL){
                this->mensaje = new char[strlen(mensaje)+1];
                strcpy(this->mensaje, mensaje);
            }else{
                this->mensaje = NULL;
            }
        }
                
    }

    //Constructor copia
    TCalendario::TCalendario(const TCalendario& cal){

        if (fechaCorrecta(cal.dia, cal.mes,cal.anyo))
        {
            this->dia = cal.dia;
            this->mes = cal.mes;
            this->anyo = cal.anyo;
            if (cal.mensaje != NULL){
                delete [] this->mensaje;
                this->mensaje = strdup(cal.mensaje);
            }else{
                this->mensaje = NULL;
            }
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
        
        this->dia = cal.dia;
        this->mes = cal.mes;
        this->anyo = cal.anyo;
        if (this->mensaje != NULL){
            delete [] this->mensaje;
            this->mensaje = NULL;
        }

        if (cal.mensaje != NULL)
        {
            this->mensaje = strdup(cal.mensaje);
        }

        return (*this);        
    }

    TCalendario TCalendario::operator+(const int dias){
        TCalendario aux;
        aux.dia = this->dia;
        aux.mes = this->mes;
        aux.anyo = this->anyo;
        aux.ModMEnsaje(this->mensaje);
        for (int i = 1; i <= dias; i++)
        {
            aux++;
        }
        
        return aux;        
    }

    //  //Sobrecarga del operador -
    TCalendario TCalendario::operator-(const int dias){
        int diasRestantes = this->dia - dias;
        int mes = this->mes;
        int anyo = this->anyo;
        while (diasRestantes < 0)
        {
            mes--;
            if (mes < 1)
            {
                mes = 12;
                anyo--;
            }
            diasRestantes += DIAS_EN_MES[mes];
        }
        return TCalendario(diasRestantes, mes, anyo, this->mensaje);

    }

    // //Sobrecarga del operador ++ (postincremento)
    TCalendario TCalendario::operator++(int dia){
        TCalendario auxiliar(*this);
        ++(*this);
        return auxiliar;

    }

    // //Sobrecarga del operador ++ (preincremento)
    TCalendario& TCalendario::operator++(){
        this->dia++;
        if(this->dia == DIAS_EN_MES[this->mes]){
            this->dia = 1;
            this->mes++;
            if (this->mes == 13)
            {
                this->mes = 1;
                this->anyo++;
            }
        }
        return *this;
    }

    // //Sobrecarga del operador -- (postdecremento)
    TCalendario TCalendario::operator--(int dias){
        TCalendario auxiliar(*this);
        --(*this);
        return auxiliar;
    }

    // //Sobrecarga del operador -- (predecremento)
    TCalendario& TCalendario::operator--(){
        this->dia--;
        if(this->dia == 0){
            this->mes--;
            if (this->mes == 0)
            {
                this->mes = 12;
                this->anyo--;
            }
        }

        return *this;
    }

    // //Modifica el mensaje
    bool TCalendario::ModMEnsaje(char* mensaje){
        if (mensaje == NULL)
        {
            delete [] this->mensaje;
            this->mensaje = NULL;
        }else{
            this->mensaje = new char[strlen(mensaje)+1];
            strcpy(mensaje, mensaje);
        }
        return true;
    }

    // //Sobrecarga del operador ==
    bool TCalendario::operator==(const TCalendario& cal){
        return (this->dia == cal.dia && this->mes == cal.mes && this->anyo == cal.anyo && strcmp(this->mensaje, cal.mensaje) == 0);
    }

    // //Sobrecarga del operador !=
    bool TCalendario::operator!=(const TCalendario& cal){
        return !(*this == cal);
    }

    // //Sobrecarga del operador <
    bool TCalendario::operator<(const TCalendario& cal){
        return !(*this > cal);        
    }

    // //Sobrecarga del operador >
    bool TCalendario::operator>(const TCalendario& cal){
        bool fechaMayor = (this->anyo >= cal.anyo && this->mes >= cal.mes && this->dia > cal.dia);
        bool fechaIgual = (this->anyo == cal.anyo && this->mes == cal.mes && this->dia == cal.dia);
        bool ambosMsgNotNull = (this->mensaje != NULL && cal.mensaje != NULL);

        if (fechaMayor || (fechaIgual && ambosMsgNotNull && strcmp(this->mensaje, cal.mensaje) > 0))
        {
            return true;
        }else 
        {
            return false;
        }
        
    }

    // //TCalendario vacío
    bool TCalendario::EsVacio(){
        return (this->dia == 1 && this->mes == 1 && this->anyo == 1900 && this->mensaje == NULL);
    }

    // //Devuelve el día
    int TCalendario::Dia(){
        return this->dia;
    }

    // //Devuelve el mes
    int TCalendario::Mes(){
        return this->mes;
    }

    // //Devuelve el año
    int TCalendario::Anyo(){
        return this->anyo;
    }

    // //Devuelve el mensaje
    char* TCalendario::Mensaje(){
        return this->mensaje;
    }

    ostream & operator<<(ostream & os, const TCalendario & cal){
        os << (cal.dia < 10 ? "0" + to_string(cal.dia) : to_string(cal.dia))  << "/" << (cal.mes < 10 ? "0" + to_string(cal.mes) : to_string(cal.mes)) << "/" << cal.anyo << " \"" << (cal.mensaje != NULL ? cal.mensaje : "") << "\"";
        return os;
    }


