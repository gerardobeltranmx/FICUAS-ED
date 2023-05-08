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

    T eliminarInicio(){
        T dato;
        Nodo *aux;
        aux = Raiz;
        Raiz = Raiz->enl;
        dato = aux->info;
        delete aux;
        return dato;
    }
    void agregarFinal(T dato){

       if (Raiz==NULL){
            agregarInicio(dato);
       }
       else{
          Nodo *aux = Raiz;   
          while (aux->enl!=NULL){
            aux=aux->enl;
          }
          // crea nuevo nodo
          Nodo *nuevo = new Nodo;
          nuevo->info = dato;
          nuevo->enl = NULL;
          // colocamos al final 
          aux->enl = nuevo;
       }     



    }


    void imprimir(){
        Nodo *aux;
        aux = Raiz;

        while (aux!=NULL){
            cout << aux->info << " ";
            aux = aux->enl;
        }
        cout << endl;
    }
};

int main()
{

    Lista <int> miLista;

    miLista.agregarInicio(6);
    miLista.agregarInicio(8);
    miLista.agregarInicio(7);
    miLista.agregarInicio(1);
    miLista.agregarInicio(5);
    miLista.agregarFinal(20);
    miLista.agregarFinal(30);
    miLista.agregarFinal(40);
    miLista.agregarInicio(54);
    
    miLista.imprimir();
    cout << "Se elimino el: " << miLista.eliminarInicio()<< endl;
    miLista.imprimir();
    cout << "Se elimino el: " << miLista.eliminarInicio()<< endl;
    miLista.imprimir();

        
    

    return 0;
}