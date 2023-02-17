#include <iostream>
using namespace std;

class Temperatura{
    private:
        int gradosF;
    public:
        Temperatura(){
            gradosF = 0;
        }        
        Temperatura(int valor){
            gradosF = valor;
        }    
        void CambiarGradosFahrenheit(int valor){
            gradosF = valor;
        }
        int ObtenerGradosCelsius(){
           int gradosC;    
           gradosC = 5 * ( gradosF - 32) / 9;
           return gradosC;
        }  
        int ObtenerEstadoTemp(){
            int temp;
            temp = ObtenerGradosCelsius();
            //return temp <=36?0:1;
            if (temp<=36)
                return 0;
            else
                return 1;
        } 
};

int main()
{
    int temp;    
    cin >> temp;
    Temperatura Termometro(temp);
    
    cout << Termometro.ObtenerGradosCelsius() << " " <<
            Termometro.ObtenerEstadoTemp() << endl;
    
    

    return 0;
}
