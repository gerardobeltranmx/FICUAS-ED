#include <iostream>

using namespace std;

class Arreglo {
    private: 
        int *datos;
        int ultimo;
        int longitud;
    public:
    Arreglo (int tam){
        datos = new int[tam];
        longitud = tam;
    } 
    ~Arreglo(){
        delete [] datos;
    }
    Arreglo(){
        ultimo = -1;
        datos = new int[100];
        longitud = 100;
        
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

    int ObtenerElementoMenor(){
        int menor = ObtenerElemento(0);
          
        for (int i=1; i < ObtenerNumeroElementos(); i++){
            if (menor > ObtenerElemento(i)){
                menor = ObtenerElemento(i);
            }
        }
        return menor;
       }

    int ObtenerElementoMayor(){
        int mayor = ObtenerElemento(0);
          
        for (int i=1; i < ObtenerNumeroElementos(); i++){
            if (mayor < ObtenerElemento(i)){
                mayor = ObtenerElemento(i);
            }
        }
        return mayor;
       }
       
    int ObtenerElementoPosicion(int dato){
        int mayor = ObtenerElemento(0);
        int posicion=-1; 
        for (int i=0; i < ObtenerNumeroElementos() and posicion==-1; i++){
            if (dato == ObtenerElemento(i)){
                posicion=i;
            }
        }
        return posicion;
    }

    void OrdenarPorIntercambio(){
        // Metodo de la Burbuja

        int i, j;  
        for(i=0; i<ObtenerNumeroElementos()-1; i++){
            for(j=0; j<ObtenerNumeroElementos()-1-i; j++){
                if (datos[j]>datos[j+1]){
                    int aux=datos[j];
                    datos[j]=datos[j+1];
                    datos[j+1]=aux; 
                }
            }
        }        
    } 


    int ObtenerSumatoria(){
        int suma =0;
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
    Arreglo edades(20);
    
    edades.AgregarElemento(4);
    edades.AgregarElemento(56);
    edades.AgregarElemento(43);
    edades.AgregarElemento(14);
    edades.AgregarElemento(23);
    
    cout << edades.ObtenerNumeroElementos() << endl;
    cout << edades.ObtenerLongitudMaxima() << endl;
    cout << edades.ObtenerSumatoria() << endl;
    cout << edades.ObtenerPromedio() << endl;
    cout << edades.ObtenerElementoMenor() << endl;
    cout << edades.ObtenerElementoMayor() << endl;
    cout << edades.ObtenerElementoPosicion(43) << endl;
    
    for (int i=0; i < edades.ObtenerNumeroElementos(); i++){
        cout << edades.ObtenerElemento(i) << " ";
    }
    
    return 0;
}
