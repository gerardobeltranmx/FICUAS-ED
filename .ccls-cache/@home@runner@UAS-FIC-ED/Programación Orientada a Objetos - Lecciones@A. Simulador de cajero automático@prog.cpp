#include <iostream>

using namespace std;

class CajeroAutomatico {
    
    private:
        int saldo;
    public:
        CajeroAutomatico(){
            saldo = 1000;
        }
        int ObtenerSaldo (){
            return saldo;
        }
        void Deposito(int cantidad){
            saldo = saldo + cantidad;
        }
        void Retiro (int cantidad){
            saldo = saldo - cantidad;
        }
    
};


int main()
{
    
    CajeroAutomatico objCajero;
    char op;
    int cantidad;
    do {
        //cout << "Operaciones ([D]eposito,[R]etiro,[C]onsulta, [S]alir): "; 
        
        cin >> op;
        
        switch (op){
            case 'D':
            //    cout << "Cantidad a Depositar: ";
                cin >> cantidad;
                objCajero.Deposito(cantidad);
                break;
            case 'R':
                //cout << "Cantidad a Retirar: ";
                cin >> cantidad;
                objCajero.Retiro(cantidad);
                break;
            case 'C':
                //cout << "Saldo: "; 
                cout << "$"<<objCajero.ObtenerSaldo()<< endl;
        }
        
    }while (op!='S');
    
    

    return 0;
}