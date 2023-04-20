#include <iostream>
using namespace std;
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

int main()
{
    int N;
    string tipo, cliente, nombre;
    cin >> N; // numero de eventos
    Cola <string> Trabajadores(N);
    Cola <string> Estudiantes(N);
    for (int i=0; i < N; i++){
        cin >> tipo; // tipo de operacion (llegada o atencion de cliente)
        if (tipo=="LLEGA"){
            cin >> cliente; // tipo de cliente (Trabajador o estudiante)
            cin >> nombre; // nombre del trabajador o estudiante
            if (cliente == "TRABAJADOR")
                Trabajadores.agregar(nombre);
            else
                Estudiantes.agregar(nombre);
        }
        else { // Se atiende
            if (Trabajadores.esVacia()==false) // se atiende a trabajadores si hay en espera
                cout <<Trabajadores.extraer() << endl;
            else // se atiende a estudiantes si no hay trabajadores en espera
                cout << Estudiantes.extraer() << endl;    
        }
    }
    return 0;
}