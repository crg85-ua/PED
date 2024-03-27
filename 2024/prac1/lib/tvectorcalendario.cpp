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
                this->c[i] = vector.c[i];
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
                if (this->c[i] != vector.c[i])
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
    bool TVectorCalendario::operator!=(const TVectorCalendario& vector){
        return !(*this == vector);
    }

    // //Sobrecarga del operador [] (parte IZQUIERDA) (MODIFICACION)
    TCalendario& TVectorCalendario::operator[](int index){
        if (index >= 1 && index <= this->tamano)
        {
            return this->c[index - 1];
        }else{
            return this->error;
        }
        

    }

    // //Sobrecarga del operador [] (parte DERECHA) (SOLO LECTURA)
    TCalendario TVectorCalendario::operator[](int index) const{
        if (index >= 1 && index <= this->tamano)
        {
            return this->c[index - 1];
        }else{
            return error;
        }        
    }

    // //Tamaño del vector (posiciones TOTALES)
    int TVectorCalendario::Tamano(){
        return this->tamano;
    }

    // //Cantidad de posiciones ocupadas (no vacias)
    int TVectorCalendario::Ocupadas(){
        int ocupadas = 0;
        for (unsigned i = 0; i < this->tamano; i++)
        {
            if (!this->c[i].EsVacio())
            {
                ocupadas++;
            }
        }
        return ocupadas;
    }

    // //Mira si existe el calendario en el vector
    bool TVectorCalendario::ExisteCal(const TCalendario& cal){
        bool existe = false;
        for (unsigned i = 0; i < this->tamano; i++)
        {
            if (this->c[i] == cal)
            {
                existe = true;
                break;
            }
        }
        return existe;
    }

    // //Muestra los mensajes de TCalendario en el vector, con fecha = o anterior a la del parametro
    void TVectorCalendario::MostrarMensajes(int dia, int mes, int anyo){
        bool encontrado = false;
        TCalendario aux = TCalendario(dia, mes, anyo, NULL);
        cout << "["; // Comenzamos la salida con corchetes

        for (unsigned i = 0; i < this->tamano; i++) {
            if (this->c[i].EsVacio()) continue; // Saltar elementos vacíos

            if (this->c[i] > aux || this->c[i] == aux) {
                if (encontrado) cout << ", "; // Agregamos coma y espacio si ya se ha encontrado al menos un elemento válido
                cout << this->c[i]; // Mostramos el elemento TCalendario
                encontrado = true;
            }
        }

        cout << (encontrado ? "]" : "[]") << endl; // Terminamos la salida con corchetes y añadimos un salto de línea
    }
    
    // //Redimensiona el vector de TCalendario
    bool TVectorCalendario::Redimensionar(int tam){
        if (tam > 0 && tam != this->tamano)
        {
            
            TCalendario *aux = new TCalendario[tam];
            int min = (this->tamano < tam) ? this->tamano : tam;

            for (unsigned i = 0; i < min; i++)
            {
                aux[i] = this->c[i];
            }

            delete [] this->c;
            this->c = aux;
            this->tamano = tam;
            return true;
        }else{
            return false;
        }

    }

    // //Funcion amiga
    // //Sobrecarga del operador salida
    ostream& operator<<(ostream& os, const TVectorCalendario& vector){
        os << "[";
        for (unsigned i = 0; i < vector.tamano; i++)
        {
            os << "(" << i + 1 << ") " << vector.c[i];
            if (i < vector.tamano - 1)
            {
                os << ", ";
            }
        }

        os << "]";
        return os;        
    }