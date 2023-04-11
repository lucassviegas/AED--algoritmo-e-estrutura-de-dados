#include <iostream>
using namespace std;
#define size 40
typedef int tipochave;
struct elemento 
{
    tipochave chave;
    float preco;
};

class pilha
{
    private:
        elemento *dado;
        int tamanho;
    
    public:
        pilha(); // funÃ§Ã£o criadora
        bool cheia (); //1 cheia 0 nÃ£o cheia
        bool vazia (); // 1 vazia 0 nÃ£o vazia
        void inserir (elemento e); // push
        tipochave remover(); //pop
        void mostrar ();
        int gettamanho (); 
        bool busca (tipochave ch);
};

int main()
{
    pilha p1,p2;
    elemento e1;
    tipochave ch1;
    int menu,menu1;
   while(true){
    cout<<"faÃ§a uma escolha \n";
    cout<<"digite 0 para sair do programa\ndigite 1 para usar a pilha 1\ndigite 2 para usar a pilha 2\n";
    cin>>menu1;
    switch(menu1)
    {
    case 0:
    return 0;
    break;
    case 1:
    do{
       cout<<"digite: \n";
        cout<<" 0 para voltar para o menu anterior \n";
        cout<<" 1 para inserir um elemento \n"; 
        cout<<" 2 para remover um elemento \n"; 
        cout<<" 3 para ver todos os elementos da pilha\n"; 
        cout<<" 4 para ver o tamanho da pilha \n"; 
        cout<<" 5 para buscar por um elemento \n";
        cin>>menu;
        switch (menu)
        {
            case 0:
            break;
            case 1: cout<<"digite a chave do elemento a ser inserido";
                     cin>>e1.chave;
                     cout<<"digite o preco do elemento\n";
                     cin>>e1.preco;
                     p1.inserir (e1);  break;
            case 2: cout<<p1.remover() <<"\n";  break;
            case 3:  p1.mostrar();  break;
            case 4:  cout<< "o tamanho da pilha Ã©: " <<p1.gettamanho() <<"\n";
                     break;
            case 5: cout<<"digite a chave do elemento a ser procurado\n";
                cin>>ch1;
                if (p1.busca(ch1)==1){  cout<<"o elemnto jÃ¡ estÃ¡ na pilha\n"; }
                else { cout<<"o elemnto nÃ£o estÃ¡ na pilha\n";} break;
            default: cout<<"opÃ§Ã£o invalida \n"; break;
        }
    } while(menu!=0);
    break;
    case 2:
    do{
       cout<<"digite: \n";
        cout<<" 0 para terminar \n";
        cout<<" 1 para inserir um elemento \n"; 
        cout<<" 2 para remover um elemento \n"; 
        cout<<" 3 para ver todos os elementos da pilha\n"; 
        cout<<" 4 para ver o tamanho da pilha \n"; 
        cout<<" 5 para buscar por um elemento \n";
        cin>>menu;
        switch (menu)
        {
            case 0: cout<<"The End\n"; break;
            case 1: cout<<"digite a chave do elemento a ser inserido";
                     cin>>e1.chave;
                     cout<<"digite o preco do elemento\n";
                     cin>>e1.preco;
                     p1.inserir (e1);  break;
            case 2: cout<<p1.remover() <<"\n";  break;
            case 3:  p1.mostrar();  break;
            case 4:  cout<< "o tamanho da pilha Ã©: " <<p1.gettamanho() <<"\n";
                     break;
            case 5: cout<<"digite a chave do elemento a ser procurado\n";
                cin>>ch1;
                if (p1.busca(ch1)==1){  cout<<"o elemnto jÃ¡ estÃ¡ na pilha\n"; }
                else { cout<<"o elemnto nÃ£o estÃ¡ na pilha\n";} break;
            default: cout<<"opÃ§Ã£o invalida \n"; break;
        }
        
    } while(menu!=0);
    break;
    default:break;
    }
   }
    return 0;
}
pilha::pilha ()
{
    tamanho=0; 
    dado=new elemento [size];
}

bool pilha::cheia ()
{
    if(tamanho==size) {return true;}
    else { return false;}
}
bool pilha::vazia()
{
    if(tamanho==0) {return true;}
    else { return false;}
}
bool pilha::busca (tipochave ch)
{
     int i;
    for(i=0; i<tamanho; i++)
    {
        if (dado[i].chave==ch) 
        {
            return true;
        }
    }
     return false;
}
void pilha::inserir (elemento e)
{
    int a;
    a=cheia(); // para inserir primeiro devemos checar se nÃ£o estÃ¡ cheia
    if(a==1) 
    {
        cout<<"a pilha jÃ¡ estÃ¡ cheia\n";
     //se estÃ¡ cheia nÃ£o podemos inserir  
    }
    else
    {  /// se nÃ£o estÃ¡ cheia, antes de inserir devemos procurar se o elemento 
        // jÃ¡ estÃ¡ na pilha
        if (busca (e.chave)==1) // se ele estÃ¡, nÃ£o podemos inserir
        {
            cout<<"o elemento com chave " <<e.chave << " jÃ¡ estÃ¡ na pilha\n";
        }
        else
        {
        dado [tamanho]=e; //inserimos o elemento no topo
        tamanho=tamanho+1; // aumentamos a quantidade de elementos
        }
    }
}
tipochave pilha::remover()
{
    int a;
    a=vazia(); //sÃ³ poderemos remover se a pilha nÃ£o estiver vazia
    if(a==1) // se a funÃ§Ã£o retornar 1, entÃ£o a pilha estÃ¡ vazia
    {
        cout<<" NÃ£o foi possivel remover: a pilha jÃ¡ estÃ£ vazia\n";
         return 0;
    }
    else //se o retorno nÃ£o Ã© 1, entÃ£o podemos remover o elemento do topo
    {
        tamanho=tamanho-1;
        cout<<"foi removido o elemento com chave: \n";
        return dado[tamanho].chave; 
        //retornamos a chave do elemento que foi removido
    }
}
void pilha::mostrar ()
{
    cout<<"os elementos da pilha sÃ£o:\n";
    int i;
    for(i=0; i<tamanho; i++)
    {
        cout<<dado[i].chave  <<" \t" <<dado[i].preco<<"\n";
    }

}
int pilha::gettamanho ()
{
    return tamanho;
}
