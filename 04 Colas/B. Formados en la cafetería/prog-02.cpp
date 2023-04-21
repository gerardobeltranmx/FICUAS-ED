#include <iostream>
using namespace std;
template <class T>
class ColaCircular{
    int tam;
    int frente, final;
    T *elementos;

    //Iniciar Cola
    public:
    ColaCircular(int N){
      elementos= new T[N];
      tam=N;
	  frente=-1;
	  final = -1;
    }       
    // Agregar un dato a la cola
    void agregar(T dato){
        if(final==tam-1) // Esta en el ultimo?
		    final=0; // se pone al principio
	else
		final++; // avanza al siguiente espacio libre
	
    elementos[final]=dato;//Se agrega dato
	if(frente==-1) //Estaba vacía?
	    frente=0; // se pone el frente en el primero
    }
    // extraer un dato de la cola
    T extraer(){

        T dato = elementos[frente];
	    if(frente==final) // solo había uno?
		    frente=final=-1; // se vacía
	    else if(frente==tam-1) //estaba en el ultimo?
		    frente=0; // se va al principio
	    else
		    frente++; // avanza al siguiente

	return dato;
    }

    //Obtener dato del tope sin extraerlo
    T cima(){
	return elementos[frente];
}

    //Determina si la Cola esta vacía
    bool esVacia(){
	    return(frente==-1)?true:false;
    }

    //Determina si la Cola esta llena
    bool esLlena(){
       return((final==tam-1 && frente==0) || (final+1==frente))?true:false;
    }

    //Obtiene numero de elementos de la Cola
    int numElementos(){
        return final+1;
    }
    //Obtiene un elemento de la Cola de alguna posición 
    T obtenerPorPosicicion(int pos){
        return elementos[pos];
    }
    int tamano(){
        return tam;
    }
};

int main()
{
    int N;
    string tipo, cliente, nombre;
    cin >> N; // numero de eventos
    ColaCircular <string> Trabajadores(N);
    ColaCircular <string> Estudiantes(N);
    for (int i=0; i < N; i++){
        cin >> tipo; // tipo de operacion (llegada o atencion de cliente)
        if (tipo=="LLEGA"){
            cin >> cliente; // tipo de cliente (Trabajador o estudiante)
            cin >> nombre; // nombre del trabajador o estudiante
            if (cliente == "TRABAJADOR")
                Trabajadores.agregar(nombre);
            else
                Estudiantes.agregar(nombre);
        }
        else { // Se atiende
            if (Trabajadores.esVacia()==false) // se atiende a trabajadores si hay en espera
                cout <<Trabajadores.extraer() << endl;
            else // se atiende a estudiantes si no hay trabajadores en espera
                cout << Estudiantes.extraer() << endl;    
        }
    }
    return 0;
}