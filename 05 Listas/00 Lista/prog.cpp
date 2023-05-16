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
    int tam;
    public:
    Lista(){
        Raiz = NULL;
        tam=0;
    }
    ~Lista(){
        eliminarTodos();
    }

    void agregarInicio(T dato){
        Nodo *nuevo;
        // crear nuevo nodo
        nuevo = new Nodo;
        nuevo->info = dato;
         //  nuevo->enl = NULL;
        nuevo->enl = Raiz;
        Raiz = nuevo;
        tam++;
    }

    T eliminarInicio(){
        T dato;
        Nodo *aux;
        aux = Raiz;
        Raiz = Raiz->enl;
        dato = aux->info;
        delete aux;
        tam--;
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
          tam++; 

       }    
    }
    T eliminarFinal(){
        Nodo *act, *sig;
        T dato;
        act = Raiz;
        sig = act->enl;

        if (sig==NULL){ // solo un nodo
            eliminarInicio();
        }
        else if (sig->enl == NULL){ // solo 2 nodos
            dato = sig->info;
            delete sig;
            act->enl =NULL; 
            tam--;
        }
        else { // 3 o mas nodos
            while (sig->enl != NULL){
                act = sig;
                sig = sig->enl;
            }
            dato = sig->info;
            delete sig;
            act->enl =NULL;
            tam--;
        }
        return dato;
    }

    void eliminarTodos(){
        Nodo *aux;
        while (Raiz!=NULL){
            aux = Raiz;
            Raiz = Raiz->enl;
            delete aux;
        }
        tam=0;
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
    int obtenerNumElementos(){
        return tam;|
    }

    bool esVacia(){
        //return tam == 0?true:false;
          return Raiz==NULL?true:false;  
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
    miLista.eliminarTodos();
    cout << "Lista vacia: " << endl;
    miLista.imprimir();
    

    /*
    cout << "Se elimino del inicio el: " << miLista.eliminarInicio()<< endl;
    miLista.imprimir();
    cout << "Se elimino  del inicio el: " << miLista.eliminarInicio()<< endl;
    miLista.imprimir();
    cout << "Se elimino del final el: " << miLista.eliminarFinal()<< endl;
    miLista.imprimir();
    */    
    

    return 0;
}