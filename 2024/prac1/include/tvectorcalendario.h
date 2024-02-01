#ifndef _TVECTORC
#define __TVECTORC
#include "tcalendario.h"

using namespace std;

class TVectorCalendario
{
private:
    TCalendario *c;
    int tamano;
    TCalendario error;
public:
    //Constructor por defecto
    TVectorCalendario();

    //Constructor a partir de un tamaño
    TVectorCalendario(int);
    
    //Constructor de copia
    TVectorCalendario(const TVectorCalendario&);

    //Destructor
    ~TVectorCalendario();

    //Sobrecarga del operador =
    TVectorCalendario& operator=(const TVectorCalendario&);

    //METODOS

    //Sobercarga del operador ==
    bool operator==(const TVectorCalendario&);

    //Sobercarga del operador !=
    bool operator!=(const TVectorCalendario&);

    //Sobrecarga del operador [] (parte IZQUIERDA)
    TCalendario& operator[](int);

    //Sobrecarga del operador [] (parte DERECHA)
    TCalendario operator[](int) const;

    //Tamaño del vector (posiciones TOTALES)
    int Tamano();

    //Cantidad de posiciones ocupadas (no vacias)
    int Ocupadas();

    //Mira si existe el calendario en el vector
    bool ExisteCal(const TCalendario&);

    //Muestra los mensajes de TCalendario en el vector, con fecha = o anterior a la del parametro
    void MostrarMensajes(int, int, int);
    
    //Redimensiona el vector de TCalendario
    bool Redimensionar(int);

    //Funcion amiga
    //Sobrecarga del operador salida
    friend ostream& operator<<(ostream&, const TCalendario&);
};

#endif
