#include <iostream>
using namespace std;
int main()
{
 int *ptr;

 int datos [] = {1,2,3,4,5,6,7,8,9,10,11,12}; 

    ptr = &datos[5];

    cout  << ptr << endl;

    return 0;
}