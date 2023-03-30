#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class Pila{
    int tam;
    int tope;
    T *elementos;

    //Iniciar Pila
    public:
    Pila(int N){
      elementos= new T[N];
      tam=N;
	  tope=-1;
    }       
    // Agregar un dato a la Pila
    void agregar(int dato){
        tope++;
        elementos[tope]=dato;
    }
    // extraer un dato de la pila
    T extraer(){
        int dato;
        dato = elementos[tope];
        tope--;
        return dato;
    }
    //Obtener dato del tope sin extraerlo
    T cima(){
        return elementos[tope];
    }

    //Determina si la Pila esta vacía
    bool esVacia(){
        return(tope==-1)?true:false;
    }

    //Determina si la Pila esta llena
    bool esLlena(){
        return (tope==tam-1)?true:false;
    }

    //Obtiene numero de elementos de la Pila
    int numElementos(){
        return tope+1;
    }
    //Obtiene un elemento de la Pila de alguna posición 
    T obtenerPorPosicion(int pos){
        return elementos[pos];
    }
    int tamaño(){
        return tam;
    }
};


int main()
{
   char cadena[1000001];
   int tam;
   // entrada de los parentesis 
   cin >> cadena; 
   tam = strlen(cadena); // tamaño de la cadena
   Pila <char> miPila(tam);   // creamos la pila
   bool error = false;
   for (int i=0; i< tam and error==false; i++) {
        if (cadena[i]=='('){
            miPila.agregar(cadena[i]);
        }
        else {
           if (miPila.esVacia()){
            error=true;
           }
           else{
                miPila.extraer();
           }
       }
   }
   if (error == false and miPila.esVacia()==true ) {
        cout << "SI" << endl;
   }
   else{
        cout << "NO" << endl;
   }







    return 0;
}