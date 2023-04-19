#include  <iostream>
using namespace std;

template <class T>
class Cola{
    int tam;
    int frente, final;
    T *elementos;

    //Iniciar Cola
    public:
    Cola(int N){
      elementos= new T[N];
      tam=N;
	  frente=0;
	  final = -1;
	  
    }       
    // Agregar un dato a la cola
    void agregar(int dato){
        final++;
	    elementos[final]=dato;

    }
    // extraer un dato de la cola
    T extraer(){
       int i;
       T dato = elementos[frente];
	
	    for(i=0; i<final-1; i++)
		    elementos[i]=elementos[i+1];
	
	    final--;
	
	return dato;

    }
    //Obtener dato del tope sin extraerlo
    T cima(){
        return elementos[frente];
    }

    //Determina si la Cola esta vacía
    bool esVacia(){
        return (final==-1)?true:false;
    }

    //Determina si la Cola esta llena
    bool esLlena(){
        return (final==tam-1)?true:false;
    }

    //Obtiene numero de elementos de la Cola
    int numElementos(){
        return final+1;
    }
    //Obtiene un elemento de la Cola de alguna posición 
    T obtenerPorPosicion(int pos){
        return elementos[pos];
    }
    int tamano(){
        return tam;
    }
};

int main(){
int N;
char tipo;
cin >> N;
Cola <char> Fila(N);
for (int i=0; i<N; i++ ){
    cin >> tipo; // posibles valores E, N, F
    switch(tipo){
        case 'E':
               Fila.agregar('E');
               break;
        case 'N':
            if (Fila.numElementos() <= 4){
                Fila.agregar('N');
                cout << "espera" << endl;
            }   
            else {
                cout << "no espera" << endl;     
            }
            break;    
        case 'F':
            Fila.extraer();    
            break;    
    }
} 
}