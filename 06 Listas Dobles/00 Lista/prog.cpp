#include <iostream>

using namespace std;

template <class T>
class ListaDoble {
    class Nodo{
       public:
        T info;
        Nodo *ant;
        Nodo *sig;
    };
    Nodo *Raiz;
    int tam;
    public:
    ListaDoble(){
        Raiz = NULL;
        tam=0;
    }
    ~ListaDoble(){
        eliminarTodos();
    }

    void agregarInicio(T dato){
        Nodo *nuevo;
        // crear nuevo nodo
        nuevo = new Nodo;
        nuevo->info = dato;
        nuevo->ant = NULL;
        nuevo->sig = NULL;

        nuevo->sig= Raiz; // Coloca nodo al inicio de lista

     if (Raiz!=NULL) // Si no esta vacía
         Raiz->ant=nuevo; //Hacer referencia al nuevo primer
   
     Raiz = nuevo; // El inicio de lista cambia al nuevo
     tam++;
    }


 void imprimir(){
        Nodo *aux;
        aux = Raiz;

        while (aux!=NULL){
            cout << aux->info << " ";
            aux = aux->sig;
        }
        cout << endl;
    }
    
    void eliminarTodos(){
        Nodo *aux;
        while (Raiz!=NULL){
            aux = Raiz;
            Raiz = Raiz->sig;
            delete aux;
        }
        tam=0;
    }
    
       /*  T eliminarInicio(){
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
        return tam;
    }

    bool esVacia(){
        //return tam == 0?true:false;
          return Raiz==NULL?true:false;  
    }

    bool buscarPorIndice(int indice, T &dato){
        Nodo *aux = Raiz;
        int cont=0;
        bool enc=false;

        for (int i=0; i<obtenerNumElementos() and enc==false; i++ ){
                if (i==indice){
                    enc = true;
                    dato = aux->info;
                }    
                else
                    aux = aux->enl;    
        }

        return enc; 


        

    }



    int buscarPorValor(T valor){
        Nodo *aux = Raiz;
        bool enc = false;
        int cont=0;
        while (aux!=NULL and enc == false){
            if (aux->info == valor){
               enc = true;     
            }
            else{
                aux= aux->enl;
                cont++;
            }
        }
        return enc==true?cont:-1;
    }


 */
};

int main()
{

    ListaDoble <int> miLista;

    miLista.agregarInicio(6);
    miLista.agregarInicio(8);
    miLista.agregarInicio(7);
    miLista.agregarInicio(1);
    miLista.agregarInicio(5);
    miLista.imprimir();


    return 0;

   /*  miLista.agregarFinal(20);
    miLista.agregarFinal(30);
    miLista.agregarFinal(40);
    miLista.agregarInicio(54);  */
    //miLista.eliminarTodos();
  /* cout << "Buscar por valor:" ;
  cout << miLista.buscarPorValor(711) << endl;

  cout << "Buscar por indice:";
    int dato;
    if (miLista.buscarPorIndice(10, dato)==true)
        cout << dato<< endl;
    else
        cout << "No esta :(" << endl;    
 */

   // cout << "Lista vacia: " << endl;
//    miLista.imprimir();
    


    /*
    cout << "Se elimino del inicio el: " << miLista.eliminarInicio()<< endl;
    miLista.imprimir();
    cout << "Se elimino  del inicio el: " << miLista.eliminarInicio()<< endl;
    miLista.imprimir();
    cout << "Se elimino del final el: " << miLista.eliminarFinal()<< endl;
    miLista.imprimir();
    */    
    

}