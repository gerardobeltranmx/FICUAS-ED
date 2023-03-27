#include  <iostream>
using namespace std;
class TPila{
    int tam;
    int tope;
    int *elementos;

    //Iniciar Pila
    public:
    TPila(int N){
      elementos=(int*)malloc(sizeof(int)*N);
      tam=N;
	  tope=-1;
}
    // Agregar un dato a la Pila
    void agregarPila(int dato){
        tope++;
        elementos[tope]=dato;
    }

    int extraerPila(){
        int dato;
        dato = elementos[tope];
        tope--;
        return dato;
    }
    //Obtener dato del tope sin extraerlo
    int obtenerElementoTopePila(){
        return elementos[tope];
    }

    //Determina si la Pila esta vacía
    bool vaciaPila(){
        return(tope==-1)?true:false;
    }

    //Determina si la Pila esta llena
    bool llenaPila(){
        return (tope==tam-1)?true:false;
    }

    //Obtiene numero de elementos de la Pila
    int numElementosPila(){
        return tope+1;
    }
    //Obtiene un elemento de la Pila de alguna posición 
    int obtenerElementoPila(int pos){
        return elementos[pos];
    }
};

int main(){

    TPila miPila (10);


    miPila.agregarPila(7);
    miPila.agregarPila(9);
    miPila.agregarPila(1);
    miPila.agregarPila(4);

    cout << miPila.vaciaPila() << endl;

    std::cout << miPila.extraerPila() << std::endl;
    std::cout << miPila.extraerPila() << std::endl;
    std::cout << miPila.extraerPila() << std::endl;
    std::cout << miPila.extraerPila() << std::endl;

    cout << miPila.vaciaPila() << endl;



    




}