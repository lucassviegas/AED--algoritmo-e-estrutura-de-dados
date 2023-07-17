#include <iostream>
#include <cmath>
using namespace std;
struct polar
{
   float modulo;
   float angulo;
};
void F2(polar p2)
{
    float x, y;
    x=p2.modulo*cos(p2.angulo*3.1415/180);
    y=p2.angulo*sin(p2.angulo*3.1415/180);
    cout<<"as coordenadas retanculares serão: \n";
    cout<<"x= "<<x<<"\n";
    cout<<"y= "<<y<<"\n";
}
void F1(polar p1)
{
   cout<<"insira o valor do modulo\n";
   cin>>p1.modulo;
   cout<<"insira o valor do angulo em graus\n";
   cin>>p1.angulo;
   F2(p1);
}

int main()
{  
    polar p1;
    F1(p1);
   
    return 0;
}
