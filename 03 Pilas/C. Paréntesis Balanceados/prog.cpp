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
    int tamano(){
        return tam;
    }
};


int main()
{
    Pila <char> miPila(1000);
    char cadena[1000];
    int N;

    cin >> N;

   for (int k=0; k<N; k++){ 

   cin >> cadena;

   int tam = strlen(cadena); 
   bool error = false;
   char abierto; 
    for (int i=0; i <tam and error==false; i++){
        char c = cadena[i];
        if (c=='(' or c=='[' or c=='{'){
            miPila.agregar(c);
        }    
        else{
            if (!miPila.esVacia()){
                abierto = miPila.extraer();
                switch(abierto){
                    case '(':
                        if (c!=')') error=true;
                        break;
                    case '[':
                        if (c!=']') error=true;
                        break;
                    case '{':
                        if (c!='}') error=true;
                        break;
                      
                }

            }    
            else{
                error=true;
            }
        }

      
    } // fin i
     if (error==false and miPila.esVacia())
            cout << "SI"<< endl;
        else
            cout << "NO" << endl;    


    }// fin k




    return 0;
}