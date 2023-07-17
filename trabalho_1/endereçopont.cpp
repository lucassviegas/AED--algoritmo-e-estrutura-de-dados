#include <iostream>
using namespace std;

int main()
 {
 	int x=0;
 	int y=0;
 	cout<<"o endereco de x e: "<<&x<<endl<<"e o endereco de y e: "<<&y<<endl;
 	if(&x>&y)
 	{
 	   cout<<"o maior endereco das duas variaveis e o de x. com o endereco "<<&x;
 	   cout<<endl<<"e o conteudo de y e "<<y;
 }
 	else
 	 {
 	   cout<<"o maior endereco das duas variaveis e o de y. com o endereco "<<&y;
 	   cout<<endl<<"e o conteudo de x e "<<x;
 }
 	
 	
 	
 return 0;	
 }
