#include <iostream>

#define longitud 1000000

using namespace std;

class arreglo {
    int datos[longitud];
    int ultimo;
    public:
        int longMaxima(){
            return longitud;
        }
        int obtenerNumElementos(){
            return ultimo+1;
        } 
       arreglo(){
           ultimo=-1;
        }
    
       void agregarElemento(int dato){
             ultimo++;
            datos[ultimo]=dato;
       }
       int obtenerElemento(int pos){
           return datos[pos];
       }    
       void cambiarElemento(int pos, int dato){
           datos[pos]=dato;
       }
};


int main()
{
    arreglo vasos;
    int posicion, N, C;
    //cout << "Cantidad de vasos y canicas: ";
    cin >> N >> C;
    
    for (int i=0; i< N; i++){
        vasos.agregarElemento(0);
    }
    
    for (int i=0; i < C; i++ ){
        cin >> posicion;
        vasos.cambiarElemento(posicion-1,
                vasos.obtenerElemento(posicion-1) + 1);
    }

    for (int i=0; i<vasos.obtenerNumElementos(); i++){
        cout << vasos.obtenerElemento(i) << endl;
    }

    return 0;
}