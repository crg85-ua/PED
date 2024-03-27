    #include "tvectorcalendario.h"

    // //Constructor por defecto
    TVectorCalendario::TVectorCalendario(){
        this->c = NULL;
        this->tamano = 0;
        this->error = TCalendario();
    }

    // //Constructor a partir de un tamaño
    TVectorCalendario::TVectorCalendario(int tam){

        if (tam > 0)
        {
            this->c = new TCalendario[tam];
            this->tamano = tam;
        }else{
            this->c = NULL;
            this->tamano = 0;
            
        }
        this->error = TCalendario();      

    }
    
    // //Constructor de copia
    TVectorCalendario::TVectorCalendario(const TVectorCalendario& vector){

        this->~TVectorCalendario();
        this->tamano = vector.tamano;
        this->c = new TCalendario[vector.tamano];

        for (unsigned i = 0; i < this->tamano; i++)
        {
            this->c[i] = vector[i];
        }
        
        
    }

    // //Destructor
    TVectorCalendario::~TVectorCalendario(){
        if (this->c != NULL)
        {
            delete [] this->c;
            this->c = NULL;
            this->tamano = 0;
        }
        
    }

    // //Sobrecarga del operador =
    TVectorCalendario& TVectorCalendario::operator=(const TVectorCalendario& vector){
        if (this != &vector && vector.tamano > 0)
        {
            this->~TVectorCalendario();
            this->tamano = vector.tamano;
            this->c = new TCalendario[vector.tamano];

            for (unsigned i = 0; i < this->tamano; i++)
            {
                this->c[i] = vector[i];
            }
        }
        
        return (*this);
    }

    // //METODOS

    // //Sobercarga del operador ==
    bool TVectorCalendario::operator==(const TVectorCalendario& vector){
        bool iguales = true;
        if (this->tamano == vector.tamano)
        {
            for (unsigned i = 0; i < this->tamano; i++)
            {
                if (this->c[i] != vector[i])
                {
                    iguales = false;
                    break;
                }
            }
            
        }else{
            iguales = false;
        }
        
        return iguales;
    }

    // //Sobercarga del operador !=
    // bool operator!=(const TVectorCalendario&);

    // //Sobrecarga del operador [] (parte IZQUIERDA) (MODIFICACION)
    // TCalendario& operator[](int);

    // //Sobrecarga del operador [] (parte DERECHA) (SOLO LECTURA)
    // TCalendario operator[](int) const;

    // //Tamaño del vector (posiciones TOTALES)
    // int Tamano();

    // //Cantidad de posiciones ocupadas (no vacias)
    // int Ocupadas();

    // //Mira si existe el calendario en el vector
    // bool ExisteCal(const TCalendario&);

    // //Muestra los mensajes de TCalendario en el vector, con fecha = o anterior a la del parametro
    // void MostrarMensajes(int, int, int);
    
    // //Redimensiona el vector de TCalendario
    // bool Redimensionar(int);

    // //Funcion amiga
    // //Sobrecarga del operador salida
    // friend ostream& operator<<(ostream&, const TCalendario&);