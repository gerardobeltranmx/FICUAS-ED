#include <iostream>

using namespace std;


#define longitud 1000
class Arreglo {
    private: 
        int datos[longitud];
        int ultimo;
    public: 
    Arreglo(){
        ultimo = -1;
    }
    void AgregarElemento(int dato){
        ultimo++;
        datos[ultimo] = dato;
    }  
    
    int ObtenerElemento (int pos){
        return datos[pos];
    }
    void CambiarElemento (int pos, int nuevoDato){
        datos[pos] = nuevoDato;
    }
    int ObtenerLongitudMaxima(){
        return longitud;
    } 
    int ObtenerNumeroElementos (){
        return ultimo + 1;
    }
};

int main()
{
    Arreglo edades;
    
    edades.AgregarElemento(4);
    edades.AgregarElemento(56);
    edades.AgregarElemento(43);
    edades.AgregarElemento(14);
    edades.AgregarElemento(23);
    
    cout << edades.ObtenerNumeroElementos() << endl;
    cout << edades.ObtenerLongitudMaxima() << endl;
    
    for (int i=0; i < edades.ObtenerNumeroElementos(); i++){
        cout << edades.ObtenerElemento(i) << " ";
    }
    
    
    return 0;
}
