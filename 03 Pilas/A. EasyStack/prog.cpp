#include <iostream>
using namespace std;
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
    void agregar(int dato){
        tope++;
        elementos[tope]=dato;
    }
    // extraer un dato de la pila
    T extraer(){
        int dato;
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
    T obtenerPorPosicion(int pos){
        return elementos[pos];
    }
    int tamaño(){
        return tam;
    }
};

int main()
{
    int N, p, dato;

    cin >> N;
    Pila <int> miPila(N);

    for (int i=0; i < N; i++){
        cin >> p; // esperamos 1, 2 o 3

        switch(p){
          case 1:
            cin >> dato;
            miPila.agregar(dato);
            break;
          case 2:
            if (miPila.esVacia()==false){
                miPila.extraer();
            }
            break;
          case 3:
            if (miPila.esVacia()==false){
                cout << miPila.cima() << endl;
            }  
            else {
                cout << "Empty!" << endl;
            }

        }


    }



    return 0;
}