#include <iostream>

using namespace std;
#define size 50
typedef int tipochave;
struct elemento
{
  tipochave chave;
  //outros campos
};
class pilha
{
  private:elemento * dado;
  int tamanho;
public:
    pilha (); //funC'C#o criadora
  bool cheia (); //1 cheia 0 nC#o cheia
  bool vazia (); //1 vazia 0 nC#o vazia
  void inserir (elemento e); //push
  tipochave remover (); //pop
  void mostrar ();
  int gettamanho ();
  bool busca (tipochave ch);

};
pilha::pilha(){
    tamanho=0;
    dado= new elemento[size];
}
bool pilha::cheia()
{
    if(tamanho==size)
    {return true; }
    else{return false;}
    
}
bool pilha::vazia()
{
    if(tamanho==0)
    {return true;}
    else{return false;}
}
bool pilha::busca(tipochave ch)
{
    int i;
    for(i=0; i<tamanho; i++)
    {
        if(dado[i].chave==ch)
        {
            return true;
        }
    }
    return false;
}
void pilha::inserir(elemento e)
{
    int a;
    a=cheia();//para inserir devemos checar se não esta cheia
    if(a==1)
    {
        cout<<"a pilha ja esta cheia\n";//se esta cheia nao podemos inserir
    }
    else
    {
        //se nao esta cheia, antes de inserir devemos procurar se o elemento ja esta na pilha
    if(busca(e.chave)==1)//se ele esta, nao podemos inserir
    {
       cout<<"o elemento com chave "<<e.chave<<"ja esta na pilha\n"; 
    }
    else
    {
        dado[tamanho]=e;
        tamanho=tamanho+1;
    }
        
  } 
}
tipochave pilha::remover()
{
    int a;
    a=vazia();//so podemos remover se a pilha nao estiver vazia
    if(a==1)//se a funçao retornar 1, entao a pilha esta vazia
    {
        cout<<"nao foi possivel remover: a pilha ja esta vazia\n";
        return 0;
    }
    else//se o retorno nao e 1, entao podemos remover o elemento do topo
    {
        tamanho=tamanho-1;
      cout<<"foi removido o elemento com a chave: \n";
      return dado[tamanho].chave;
    }
}
void pilha::mostrar()
{
    cout<<"os elementos  da pilha sao: \n";
    int i;
    for(i=0; i<tamanho; i++)
    {
        cout<<dado[i].chave<<"\n";
    }
}
int pilha::gettamanho()
{
    return tamanho;
}

int main()
{
  pilha p1;
  elemento e1;
  tipochave ch1;
  int menu;
  cout << "faça uma escolha \n";
  do
    {
      cout << "Write: \n";
      cout << "0 para terminar \n";
      cout << "1 para inserir um elemento \n";
      cout << "2 para remover um elemento \n";
      cout << "3 para ver todos os elementos da pilha \n";
      cout << "4 para ver o tamanho da pilha \n";
      cout << "5 para buscar por um elementos \n";
      cin >> menu;
      switch (menu)
{
case 0:
 cout << "the end \n";
 break;
case 1:
 cout << "enter the key of the element to be inserted";
 cin >> e1.chave;
 p1.inserir (e1);
 break;
case 2:
 cout << p1.remover () << "\n";
 break;
case 3:
 p1.mostrar ();
 break;
case 4:
 cout << "o tamanho da chave e: "<<p1.gettamanho()<<"\n";
 break;
case 5:
 cout << "digite a chave do elemento a ser procurado";
 cin>>ch1;
 if(p1.busca(ch1==1))
 {
     cout<<"o elemento esta na pilha \n";
     
 }
 else
 {
     cout<<"o elemento não esta na pilha\n";
     
 }
 break;
 default:
 cout<<"opção invalida\n";
 break;
}
    }
    while(menu!=0);

  return 0;
  }
