#include <iostream>

using namespace std;

class alumno {
    
    private:
        float Cal;
    public:
        alumno(){
            Cal =0;
        }
        void ObtenerNotas(float Cal){
         if(Cal>0&&Cal<6.0) {
            cout<<"NA";
           }else if(Cal>6.0&&Cal<7.5) {
              cout<<"S";
           }else if(Cal>7.5&&Cal<9.0) {
               cout<<"B";
           }else if(Cal>9.0&&Cal<=10.00) {
                    cout<<"MB";
               }
        }
};


int main()
{
    
    alumno nota;
    float Cal;
    cin >> Cal;
    
    nota.ObtenerNotas(Cal);
    
    return 0;
}