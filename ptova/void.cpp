
#include <iostream>
using namespace std;

int main()
 {
int x =0;
float y=0;
	void *pont;
cout<<"os valores das variaveis do tipo int e float, respectivamente, sao: "<<x<<" e "<<y<<endl<<"agora, utilizando um ponteiro para mudar o valor das variaveis, \ninsira o valor da variavel int: ";
	pont=&x;
	cin>>*(int*)pont; 
cout<<"agora insira o valor da variavel float: ";
	pont=&y;
	cin>>*(float*)pont;
cout<<"os valores mudados das variaveis do tipo int e float, respectivamente, sao "<<x<<" e "<<y<<endl;
 return 0;	
 }


