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
    ~Lista(){
     Nodo *temp, *aux = Raiz;

    while(aux!=NULL){
        temp=aux;
        delete aux;
        aux=temp->enl;
    }

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
 void agregarOrdenado(T dato){
        Nodo  *act, *ant, *nuevo;
        bool enc=false;
        act = Raiz;
        ant = NULL;

        if (esVacia()){ // si es vacia lo agrega al inicio
            agregarInicio(dato);
            cout << "Vacia" << endl;
        } 
        else { // busca donde agregarlo
            cout << "Busca" << endl;
            while(act!=NULL and enc == false){
            if (act->info>dato)
                    enc=true;
            else {
                ant = act;    
                act = act->enl;
            }
       
        }
        if (ant==NULL){  // el primero es mayor 
          agregarInicio(dato);
        }
        else {
            nuevo = nuevoNodo(dato);
            ant->enl = nuevo;
            nuevo->enl = act;

        }
        }                 
     
        
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



 bool eliminarValor(T dato){
        Nodo  *act, *ant;
        bool enc=false;
        act = Raiz;
        ant = NULL;
           
        while(act!=NULL and enc == false){
           if (act->info==dato)
                enc=true;
           else {
            ant = act;    
            act = act->enl;
           }
        }

         if (enc==true){
            if (ant==NULL)
                Raiz=act->enl; // lo encontro en el primero 
            else 
                ant->enl = act->enl; // al anterior lo enlaza con el siguiente de actual
            
            delete act; // borra el actual
        } 
        return enc;
        
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
// llamadas a las funciones
    /* miLista.agregarFinal(1);
    miLista.agregarInicio(6);
    miLista.agregarInicio(8);
    miLista.agregarInicio(7); 
    miLista.agregarFinal(10);
    miLista.imprimir(); */

    miLista.agregarOrdenado(4);
    miLista.agregarOrdenado(3);
    miLista.agregarOrdenado(8);
   /* miLista.agregarOrdenado(1);
    miLista.agregarOrdenado(23);
    miLista.agregarOrdenado(13);
    miLista.agregarOrdenado(25);
    miLista.agregarOrdenado(11);
    */

    //cout << "Sale: " << miLista.eliminarValor(8)<< endl;
    miLista.imprimir();

   /*  cout << "Num. Elementos: "<< miLista.numElementos()<< endl;

    cout << "Sale: " << miLista.eliminarFinal()<< endl;
   // cout << "Sale: " <<miLista.eliminarInicio()<< endl;
   miLista.imprimir();
    cout << "Sale: " << miLista.eliminarFinal()<< endl;
   miLista.imprimir();
    cout << "Sale: " << miLista.eliminarFinal()<< endl;
   miLista.imprimir();
    cout << "Sale: " << miLista.eliminarFinal()<< endl;
   miLista.imprimir();
    cout << "Sale: " << miLista.eliminarValor(7)<< endl;
   
   miLista.imprimir();
       cout << "Num. Elementos: "<< miLista.numElementos()<< endl;
   cout << miLista.esVacia() << endl; 
 */
    // cout << "Sale: " <<miLista.eliminarFinal()<< endl;
    

    return 0;
}