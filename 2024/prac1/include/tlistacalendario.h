#ifndef _TLISTACAL
#define _TLISTACAL
#include "tcalendario.h"

using namespace std;
class TListaPos;
class TNodoCalendario;

class TListaCalendario
{
private:
    TNodoCalendario *primero;
public:
    //Constructor por defecto
    TListaCalendario();

    //Constructor de copia
    TListaCalendario(const TListaCalendario&);

    //Destructor
    ~TListaCalendario();

    //Sobrecarga del operador =
    TListaCalendario& operator=(const TListaCalendario&);

    //METODOS
    //Sobrecarga del operador ==
    bool operator==(const TListaCalendario&);

    //Sobrecarga del operador +
    TListaCalendario& operator+(const TListaCalendario&);

    //Sobrecarga del operador -
    TListaCalendario& operator-(const TListaCalendario&);

    //Inserta el elemento en la posicion que corresponda en la lista
    bool Insertar(const TCalendario&);

    //Busca y borra el elemento
    bool Borrar(const TCalendario&);
    
    //Borra el elemento en la posicion indicada
    bool Borrar(const TListaPos&);

    //Borra todos los elementos con fecha anterior la indicada
    bool Borrar(int, int, int);

    //Devuelve true si lista vacia
    bool EsVacia();

    //Obtiene el elemento que ocupa la posicion
    TCalendario Obtener(const TListaPos&);

    //Devuelve true si el calendario está en la lista
    bool Buscar(const TCalendario&);

    //Devuelve la longitud de la lista
    int Longitud();

    //Devuelve la primera posición en la lista
    TListaPos Primera();

    // Devuelve la ultima posición en la lista
    TListaPos Ultima();

    // Suma de dos sublistas en una nueva lista
    TListaCalendario SumarSubl( int I_L1, int F_L1, TListaCalendario& L2, int I_L2, int F_L2);

    //Extraer un rando de nodos de la lista
    TListaCalendario ExtraerRango(int n1, int n2);

    //Funciones amigas

    //Sobrecarga del operador salida
    friend ostream& operator<<(ostream&, TListaCalendario&);

};

class TNodoCalendario
{
    friend class TListaCalendario;
    friend class TListaPos;
private:
    TCalendario c; 
    TNodoCalendario *siguiente;

public:
    //Constructor por defecto
    TNodoCalendario();

    //Constructor de copia
    TNodoCalendario(const TNodoCalendario&);

    //Destructor
    ~TNodoCalendario();

    //Sobrecarga del operador =
    TNodoCalendario& operator=(const TNodoCalendario&);
};

class TListaPos
{
    friend class TListaCalendario;
    friend class TNodoCalendario;
private:
    TNodoCalendario *pos;
public:
    //Constructor por defecto
    TListaPos();

    //Constructor de copia
    TListaPos(const TListaPos&);

    //Destructor
    ~TListaPos();

    //Sobrecarga del operador =
    TListaPos& operator=(const TListaPos&);

    //METODOS
    //Sobrecarga del operador ==
    bool operator==(const TListaPos&);

    //Sobrecarga del operador !=
    bool operator!=(const TListaPos&);

    //Devuelve la posicion siguiente
    TListaPos Siguiente();

    //Posicion vacia
    bool EsVacia();
};
#endif
