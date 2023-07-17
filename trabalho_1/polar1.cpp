#include <iostream>
#include <cmath>
using namespace std;
struct polar
{
   float modulo;
   float angulo;
};
void F1(polar p1)
{
   cout<<"insira o valor do modulo\n";
   cin>>p1.modulo;
   cout<<"insira o valor do angulo em graus\n";
   cin>>p1.angulo;
 
}

int main()
{  
    polar p1;
    F1(p1);
   
    return 0;
}

