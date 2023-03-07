#include <iostream>


using namespace std;

template <class T>
class Arreglo {
    private: 
        T *datos;
        int ultimo;
        int longitud;
    public:
    Arreglo (int tam){
        ultimo=-1;
        datos = new T[tam];
        longitud = tam;
    } 
    ~Arreglo(){
        delete [] datos;
    }
    Arreglo(){
        ultimo = -1;
        datos = new T[1000000];
        longitud = 1000000;
        
    }
    void AgregarElemento(T dato){
        ultimo++;
        datos[ultimo] = dato;
    }  
    
    T ObtenerElemento (int pos){
        return datos[pos];
    }
    void CambiarElemento (int pos, T nuevoDato){
        datos[pos] = nuevoDato;
    }
    int ObtenerLongitudMaxima(){
        return longitud;
    } 
    int ObtenerNumeroElementos (){
        return ultimo + 1;
    }

    T ObtenerElementoMenor(){
        T menor = ObtenerElemento(0);
          
        for (int i=1; i < ObtenerNumeroElementos(); i++){
            if (menor > ObtenerElemento(i)){
                menor = ObtenerElemento(i);
            }
        }
        return menor;
       }

    T ObtenerElementoMayor(){
        T mayor = ObtenerElemento(0);
          
        for (int i=1; i < ObtenerNumeroElementos(); i++){
            if (mayor < ObtenerElemento(i)){
                mayor = ObtenerElemento(i);
            }
        }
        return mayor;
       }
       
    int ObtenerElementoPosicion(T dato){
        int posicion=-1; 
        for (int i=0; i < ObtenerNumeroElementos() and posicion==-1; i++){
            if (dato == ObtenerElemento(i)){
                posicion=i;
            }
        }
        return posicion;
    }
     


    T ObtenerSumatoria(){
        T suma =0;
        for (int i=0; i < ObtenerNumeroElementos(); i++){
            suma += ObtenerElemento(i);
        }
        return suma;
    }
       
    double ObtenerPromedio (){
           return (double) ObtenerSumatoria() / ObtenerNumeroElementos();
    }

};

    
int main()
{
    int posicion, N, C;
    //cout << "Cantidad de vasos y canicas: ";
    cin >> N >> C;
    
    Arreglo <int> vasos;

    for (int i=0; i< N; i++){
        vasos.CambiarElemento(i,0);
    }
    
    for (int i=0; i < C; i++ ){
        cin >> posicion;
        vasos.CambiarElemento(posicion-1,
                vasos.ObtenerElemento(posicion-1) + 1);
    }

    for (int i=0; i< N; i++){
        cout << vasos.ObtenerElemento(i) << endl;
    }


    return 0;
}