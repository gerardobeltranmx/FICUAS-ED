#include <iostream>

using namespace std;

Template <class T>
class Lista {

    class Nodo{
        T info;
        Nodo *enl;
    };

    Nodo *Raiz;

    Lista(){
        Raiz = NULL;
    }

    void agregarInicio(T dato){
        Nodo *nuevo;
        // crear nuevo nodo
        nuevo = new Nodo;
        nuevo->info = dato;
         //  nuevo->enl = NULL;
        nuevo->enl = Raiz;
        Raiz = nuevo;
    }

    T eliminarInicio(){
        Nodo *aux;
        aux = Raiz;
        Raiz = Raiz->enl;
        delete aux;
    }
}

int main()
{

    Lista <int> miLista;

    miLista.agregarInicio(6);
    miLista.agregarInicio(8);
    miLista.agregarInicio(7);
    
    

    return 0;
}