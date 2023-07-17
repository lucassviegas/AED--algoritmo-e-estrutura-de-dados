#include <iostream>
using namespace std;

struct aluno
 {
 	int matricula;
 	float nota;
 };

int main()
{
	aluno striker;
	aluno* pont;
	pont=&striker;
	cout<<"insira sua matricula: ";
	cin>>pont->matricula;
	cout<<"agora, insira a sua nota no semestre: ";
	cin>>pont->nota;
	 while(pont->nota<0)
	  {
	  	cout<<"nota invalida, insira uma valida: ";
	  	cin>>pont->nota;
	  }
	cout<<endl<<"sua matricula e "<<striker.matricula<<" e sua nota e "<<striker.nota; 

return 0;
}


