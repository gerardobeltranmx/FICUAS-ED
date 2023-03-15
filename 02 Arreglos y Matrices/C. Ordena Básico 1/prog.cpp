#include <iostream>

using namespace std;

 template <class T>
    class Arreglo {
        T *datos;
        int ultimo;
        int longitud;
        public:
            int LongMaxima(){
                return longitud;
            }
            int ObtenerNumeroElementos(){
                return ultimo+1;
            } 
        Arreglo(int tam){
            ultimo=-1;
            longitud = tam;
            datos = new T[longitud];
            }
            
        
            void AgregarElemento(T dato){
                ultimo++;
                datos[ultimo]=dato;
            }
            T ObtenerElemento(int pos){
                return datos[pos];
            }    
            void CambiarElemento(int pos, T dato){
                datos[pos]=dato;
            }

            void OrdenarPorIntercambio(){
                int i, j;  
                for(i=0; i<ObtenerNumeroElementos()-1; i++)
                    for(j=0; j<ObtenerNumeroElementos()-1-i; j++)
                        if (datos[j]>datos[j+1]){
                            int aux=datos[j];
                            datos[j]=datos[j+1];
                            datos[j+1]=aux; 
                        }

            }
            void OrdenarPorSeleccion(){
                int menor,aux, i, j;
                for(i=0;i<ObtenerNumeroElementos(); i++){
                    menor=i;
                    for(j=i+1; j< ObtenerNumeroElementos(); j++) { // Se busca el menor
                        if(datos[j]< datos[menor])
                            menor=j;
                    }
                    aux= datos[i]; // Se intercambian los elementos
                    datos[i]=datos[menor];
                    datos[menor]=aux;
                }
            }

            
            void OrdenarPorInsercion(){
                int i, k, aux;
                for(i=1; i<ObtenerNumeroElementos(); i++){
                    aux=datos[i];
                    k=i-1;
                    while(k>=0 && aux<datos[k]){
                        datos[k+1]=datos[k] ;
                        k=k-1;
                    }
                    datos[k+1]=aux;
        }


        }
};

int main()
{
    int N, dato;
   // cout << "Tamaño de los datos: ";
    cin >> N;
    // Creamos objeto
   Arreglo <int> Numeros (N);
    // Agregamos los datos
   for (int i=0; i < N; i++){
        cin >> dato;
        Numeros.AgregarElemento(dato); 
   }
    // Ordenamos los datos
    Numeros.OrdenarPorInsercion();
    // Mostramos datos ordenados
    for (int i=0; i < Numeros.ObtenerNumeroElementos(); i++){
        cout << Numeros.ObtenerElemento(i)<< " ";
    }

    return 0;
}
