#include <iostream>
using namespace std;
// Clase Cola

template <class T>
class Cola{
    int tam;
    int frente, final;
    T *elementos;

    //Iniciar Cola
    public:
    Cola(int N){
      elementos= new T[N];
      tam=N;
	  frente=0;
	  final = -1;
	  
    }       
    // Agregar un dato a la cola
    void agregar(T dato){
        final++;
	    elementos[final]=dato;

    }
    // extraer un dato de la cola
    T extraer(){
       int i;
       T dato = elementos[frente];
            for(i=0; i<final; i++)
                elementos[i]=elementos[i+1];
            final--;
            return dato;

    }
    //Obtener dato del tope sin extraerlo
    T cima(){
        return elementos[frente];
    }

    //Determina si la Cola esta vacía
    bool esVacia(){
        return (final==-1)?true:false;
    }

    //Determina si la Cola esta llena
    bool esLlena(){
        return (final==tam-1)?true:false;
    }

    //Obtiene numero de elementos de la Cola
    int numElementos(){
        return final+1;
    }
    //Obtiene un elemento de la Cola de alguna posición 
    T obtenerPorPosicicion(int pos){
        return elementos[pos];
    }
    int tamano(){
        return tam;
    }
};

// Clase Pila

template <class T>
class Pila{
    int tam;
    int tope;
    T *elementos;

    //Iniciar Pila
    public:
    Pila(int N){
      elementos= new T[N];
      tam=N;
	  tope=-1;
    }       
    // Agregar un dato a la Pila
    void agregar(T dato){
        tope++;
        elementos[tope]=dato;
    }
    // extraer un dato de la pila
    T extraer(){
        T dato;
        dato = elementos[tope];
        tope--;
        return dato;
    }
    //Obtener dato del tope sin extraerlo
    T cima(){
        return elementos[tope];
    }

    //Determina si la Pila esta vacía
    bool esVacia(){
        return(tope==-1)?true:false;
    }

    //Determina si la Pila esta llena
    bool esLlena(){
        return (tope==tam-1)?true:false;
    }

    //Obtiene numero de elementos de la Pila
    int numElementos(){
        return tope+1;
    }
    //Obtiene un elemento de la Pila de alguna posición 
    T obtenerPorPosicicion(int pos){
        return elementos[pos];
    }
    int tamano(){
        return tam;
    }
};


int main()
{
   int N, fila;
   char tipo;
   string nombre;
   cin >> N; // numero de eventos
   Cola <string> FilaPreferente(N); // Fila para cliente buenos
   Pila <string> FilaMorosos(N);    // Fila para clientes malos

   for (int i=0; i < N; i++){
        cin >> tipo; // posibles casos: E o A
        switch(tipo){
            case 'E':  // Cliente que va llegando al banco
                cin >> fila >> nombre;
                if (fila == 1)
                    FilaPreferente.agregar(nombre);
                else 
                    FilaMorosos.agregar(nombre);            
                break;
            case 'A' : // Cliente que fue antendido
                cin >> fila;
                if (fila == 1)
                    nombre = FilaPreferente.extraer();
                else 
                    nombre = FilaMorosos.extraer();
                
                cout  <<nombre << endl;
                break; 
        }
    }

    return 0;

   } 

   


