#ifndef _TCALENDARIO
#define _TCALENDARIO
#include <ostream>
#include <set>

using namespace std;

class TCalendario
{
private:
    int dia, mes, anyo;
    char* mensaje;
    bool fechaCorrecta(int dia, int mes, int anyo);
    bool esBisiesto(int anyo);
public:
    friend ostream& operator<<(ostream&, const TCalendario&);

    //Constructor por defecto
    TCalendario();
    //Constructor con parámetros
    TCalendario(int dia, int mes, int anyo, char * mensaje);
    //Constructor copia
    TCalendario(const TCalendario &);
    //Destructor
    ~TCalendario();
    //Sobrecarga del operador =
    TCalendario& operator=(const TCalendario&);

    //METODOS
    //Sobrecarga del operador +
    TCalendario operator+(const int);

    //Sobrecarga del operador -
    TCalendario operator-(const int);

    //Sobrecarga del operador ++ (postincremento)
    TCalendario operator++(int);

    //Sobrecarga del operador ++ (preincremento)
    TCalendario& operator++();

    //Sobrecarga del operador -- (postdecremento)
    TCalendario operator--(int);

    //Sobrecarga del operador -- (predecremento)
    TCalendario& operator--();

    //Modifica el mensaje
    bool ModMEnsaje(char *);

    //Sobrecarga del operador ==
    bool operator==(const TCalendario&);

    //Sobrecarga del operador !=
    bool operator!=(const TCalendario&);

    //Sobrecarga del operador <
    bool operator<(const TCalendario&);

    //Sobrecarga del operador >
    bool operator>(const TCalendario&);

    //TCalendario vacío
    bool EsVacio();

    //Devuelve el día
    int Dia();

    //Devuelve el mes
    int Mes();

    //Devuelve el año
    int Anyo();

    //Devuelve el mensaje
    char* Mensaje();


};

#endif
