#include <iostream>
using namespace std;
template <class T>
class Lista {
    private:
        class Nodo {
        public:
            T info;
            Nodo *sig;
        };
        Nodo *raiz;
    public:
        Lista(){
            raiz = NULL;
        }
        void insertarInicio(int dato) {
            Nodo *nuevo;
            nuevo = new Nodo();
            nuevo->info = dato;
            if (raiz == NULL) {
                raiz = nuevo;
                nuevo->sig = NULL;
            }
            else {
                nuevo->sig = raiz;
                raiz = nuevo;
            }
        }
        void imprimir() {
            Nodo  *reco = raiz;
            cout << "Listado de todos los elementos.\n";
            while (reco != NULL){
                cout << reco->info << " ";
                reco = reco->sig;
            }
            cout << endl;
        }
        T extraerInicio(){
            T informacion = raiz->info;
            Nodo *bor = raiz;
            raiz = raiz->sig;
            delete bor;
            return informacion;
        }
        ~Lista() {
            Nodo *temp = raiz;
            Nodo *aux;
            while (temp != NULL){
                aux = temp;
                temp = temp->sig;
                delete aux;
            }
        }
};
int main()
{
    Lista <int> miLista ;
    miLista.insertarInicio(10);
    miLista.insertarInicio(40);
    miLista.insertarInicio(3);
    miLista.imprimir();
    cout<<"Extraemos de la pila: " <<miLista.extraerInicio()<<"\n";
    miLista.imprimir();
    
    return 0;
}
