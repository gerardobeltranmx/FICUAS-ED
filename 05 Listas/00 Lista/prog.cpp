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

     T eliminarFinal(){
        Nodo  *act, *sig;
        T dato;
        act = Raiz;
        sig = Raiz->enl;
        if(sig==NULL){
            eliminarInicio();
            /*dato = act->info; 
            delete act;
            Raiz=NULL;*/
        }
        else if(sig->enl==NULL){
            dato = sig->info;
            delete sig;
            act->enl = NULL;
        }
        else {
           
            while(sig->enl!=NULL){
                act = sig;
                sig = sig->enl;
            }
            dato = sig->info;
            delete sig;
            act->enl =NULL;
        }

        return dato;
    }

 int numElementos (){
    Nodo *inicio;
    inicio = Raiz;
    int contador=0;
    while (inicio!=NULL){
        inicio=inicio->enl;
        contador++;
    }
    return contador;
    }
    bool esVacia(){
        return Raiz==NULL?true:false;
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
    cout << "Num. Elementos: "<< miLista.numElementos()<< endl;

    cout << "Sale: " << miLista.eliminarFinal()<< endl;
   // cout << "Sale: " <<miLista.eliminarInicio()<< endl;
   miLista.imprimir();
    cout << "Sale: " << miLista.eliminarFinal()<< endl;
   miLista.imprimir();
    cout << "Sale: " << miLista.eliminarFinal()<< endl;
   miLista.imprimir();
    cout << "Sale: " << miLista.eliminarFinal()<< endl;
   miLista.imprimir();
       cout << "Num. Elementos: "<< miLista.numElementos()<< endl;
   cout << miLista.esVacia() << endl; 

    // cout << "Sale: " <<miLista.eliminarFinal()<< endl;
    

    return 0;
}