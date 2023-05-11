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

    Nodo *nuevoNodo(T dato){
        Nodo *nodo;
        nodo = new Nodo;
        nodo->info = dato;
        nodo->enl = NULL;
        return nodo;
    }
    void agregarInicio(T dato){
        Nodo *nuevo = nuevoNodo(dato);
        nuevo->enl = Raiz;
        Raiz = nuevo;
    }

      void agregarFinal(T dato){
        
        if (Raiz!=NULL){
            Nodo *nuevo = nuevoNodo(dato);
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
    Lista <int> miLista ;
    int N, dato;
    string op;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> op;
        if (op=="AGREGAR_IZQ"){
            cin >> dato;
            miLista.agregarInicio(dato);      
        }
        else if ("AGREGAR_DER"){
            cin >> dato;
            miLista.agregarFinal(dato);      
        }
        else if ("QUITAR_PRIMER"){
           cout << miLista.eliminarInicio() << "*";
        }
        else {
            cout << miLista.eliminarFinal() << "*";
        }
    }

    cout << endl;

    return 0;
}
