#include  <iostream>
class TPila{

    int tam;
    int tope;
    int *elementos;

    /Iniciar Pila
    void iniciarPila(int N){
        elementos= 	(int*)malloc(sizeof(int)*N);
        tam=N;
	    tope=-1;
}
// Agregar un dato a la Pila
void agregarPila(int dato){
	pila->tope++;
	pila->elementos[pila->tope]=dato;
}

int extraerPila(){
	int dato;
	dato = elementos[pila->tope];
	tope--;
	return dato;
}
//Obtener dato del tope sin extraerlo
int obtenerElementoTopePila(){
	return elementos[pila.tope];
}

/Determina si la Pila esta vacía
bool vaciaPila(){
	return(tope==-1)?true:false;
}

//Determina si la Pila esta llena
bool llenaPila(Tpilapila){
	return (tope==pila.tam-1)?true:false;
}

//Obtiene numero de elementos de la Pila
int numElementosPila(){
	return tope+1;
}
//Obtiene un elemento de la Pila de alguna posición 
int obtenerElementoPila(int pos){
	return elementos[pos];
}


}