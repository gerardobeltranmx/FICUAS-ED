#include <iostream>

using namespace std;

template <class T>
class Lista {

    class Nodo{
       public:
        T info;
        Nodo *enl;
    };

    Nodo *Raiz;

    public:
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

      void agregarFinal(T dato){
        Nodo *nuevo;
       
       
       if (Raiz!=NULL){
        // crear nuevo nodo
        nuevo = new Nodo;
        nuevo->info = dato;
         //  nuevo->enl = NULL;
        Nodo *temp=Raiz;
        while (temp->enl!=NULL)
            temp = temp->enl;
       temp->enl = nuevo;
       }
       else   
          agregarInicio(dato);
    }

    

    T eliminarInicio(){
        Nodo *aux;
        aux = Raiz;
        Raiz = Raiz->enl;
        T dato = aux->info;
        delete aux;
        return dato;
    }
    void imprimir (){
    Nodo *inicio;
    inicio = Raiz;

    while (inicio!=NULL){
        cout << inicio->info << " " ;
        inicio=inicio->enl;
    }
    cout << endl;
    }
};



int main()
{

    Lista <int> miLista;
     miLista.agregarFinal(1);

    miLista.agregarInicio(6);
    miLista.agregarInicio(8);
    miLista.agregarInicio(7);
     miLista.agregarFinal(10);
    miLista.imprimir();

    cout << "Sale: " <<miLista.eliminarInicio()<< endl;
    miLista.imprimir();
    

    return 0;
}