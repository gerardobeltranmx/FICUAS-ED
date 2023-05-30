#include  <iostream>
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
          //  cout << "Vacia" << endl;
        } 
        else { // busca donde agregarlo
           // cout << "Busca" << endl;
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



 bool eliminarUltimoValor(T dato){
        Nodo  *act, *ant, *actAux, *antAux;
        bool enc=false;
        actAux = act = Raiz;
        antAux = ant = NULL;
           
        while(act!=NULL){
           if (act->info==dato){
            enc=true;
            actAux=act;
            antAux=ant;
           }
            ant = act;    
            act = act->enl;
        }
        
        if (enc==true){
            if (actAux!=NULL){
                if (ant==NULL)
                    Raiz=act->enl; // lo encontro en el primero 
                else 
                    antAux->enl = actAux->enl; // al anterior lo enlaza con el siguiente de actual
                
                delete actAux; // borra el actual
            } 
        }
        return enc;
        
    }
bool eliminarPrimerValor(T dato){
        Nodo  *act, *ant;
        bool enc=false;
        act = Raiz;
        ant = NULL;
           
        while(act!=NULL and enc==false){
           if (act->info==dato){
            enc=true;
           }
           else {
            ant = act;    
            act = act->enl;
           }
        }
        

         if (act!=NULL){
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


int main(){
int N;
char tipo;
cin >> N;
Lista <char> Fila;
for (int i=0; i<N; i++ ){
    cin >> tipo; // posibles valores E, N, F
    switch(tipo){
        case 'E':
               Fila.agregarFinal('E');
               break;
        case 'N':
            if (Fila.numElementos() <= 4){
                Fila.agregarFinal('N');
                cout << "espera" << endl;
            }   
            else {
                cout << "no espera" << endl;     
            }
            break;    
        case 'F':
            Fila.eliminarInicio();    
            break;    
    }
} 
}