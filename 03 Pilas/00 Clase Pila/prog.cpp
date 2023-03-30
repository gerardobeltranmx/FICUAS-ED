#include  <iostream>
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

int main(){

    Pila<int> miPila (10);


    miPila.agregar(7);
    miPila.agregar(9);
    miPila.agregar(1);
    miPila.agregar(4);

    cout << miPila.esVacia() << endl;

    std::cout << miPila.extraer() << std::endl;
    std::cout << miPila.extraer() << std::endl;
    std::cout << miPila.extraer() << std::endl;
    std::cout << miPila.extraer() << std::endl;

    cout << miPila.esVacia() << endl;

    cout << miPila.tamaño() << endl;


    




}