
#include <iostream>


using namespace std;
void f1 (float *x, float *y, float *s){
    float produto;
    *s=*x+*y;
    *x=(*x)*(*y);
    
    
}
int main()
{   float  a=4;
    float  b=6;
    float soma;
    f1(&a, &b, &soma);
    cout<<soma<<"\n";
    cout<<"o produto e"<<a;
    return 0;
}

