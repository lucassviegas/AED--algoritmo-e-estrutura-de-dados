#include<iostream>
#include<cstdlib>
#include<cstddef>
using namespace std;

typedef int tipochave;

struct No
{
  
tipochave chave;
  
float preco;
   
struct No *esquerda;
   
struct No *direita;
 

};
typedef No *PN;
PN inicializar()
{
  return (NULL);
}
PN criarNovoNo(tipochave ch)
{
    PN NovoNo=(PN)malloc(sizeof(No));
    NovoNo->esquerda=NULL;
    NovoNo->direita=NULL;
    NovoNo->chave=ch;
    return NovoNo;
}
PN adicioanrNoNarv(PN raiz, PN No)
{
    if(raiz==NULL)
    {
        return (No);
        
    }
    if(No->chave<raiz->chave)
    {
        raiz->esquerda=adicioanrNoNarv(raiz->esquerda, No);
    }else{
        raiz->direita=adicioanrNoNarv(raiz->direita, No);
    }
    return raiz;
    
}
PN buscar(tipochave ch, PN raiz)
{
    if(raiz==NULL)
    {
    return (NULL);
    }
    if(raiz->chave==ch)
    {
    return(raiz);
    }
    if(raiz->chave>ch)
    {
        return buscar(ch, raiz->esquerda);
    }
    return buscar(ch, raiz->direita);
}
int ContarNos(PN raiz)
{
    int Qd=0;
    if(raiz==NULL)
    {
        return 0;
        
    }
    else
    {
        Qd=ContarNos(raiz->esquerda)+1+ContarNos(raiz->direita);
    }
    return Qd;
}
void mostrar(PN raiz)
{
    if(raiz!=NULL)
    {
        cout<<raiz->chave<<"\n";
        mostrar(raiz->esquerda);
        mostrar(raiz->direita);
    }
}
int main()
{
    tipochave ch;
    int menu;
    float preco;
    int q;
    PN r=inicializar();
    //r=adicioanrNoNarv(r, No);
    do{
        cout<<"\n===========================";
        cout<<"\n escolha: ";
        cout<<"\n===========================";
        cout<<"\n 0 para terminar ";
        cout<<"\n===========================";
        cout<<"\n 1 para inseriro elemento";
        cout<<"\n===========================";
        cout<<"\n 2 para ver o tmanho da arvore";
        cout<<"\n===========================";
        cout<<"\n 3 para buscar por um elemento";
        cout<<"\n===========================";
        cout<<"\n 4 para mostrar";
        cout<<"\n===========================";
        cin>>menu;
        switch(menu)
        {
            case 0:
            cout<<"fim";
            break;
            case 1:
            cout<<"insira a chave no no a ser inserido na arvore";
            cin>>ch;
            cout<<"insira tambem o preco dele";
            cin>>preco;
            PN p1;
             p1=buscar(ch, r);
            if(p1!=NULL)
            {
                cout<<"ja exite um no com essa chave \n";
            }
            else
        {
            PN No;
            No=criarNovoNo(ch);
            r=adicioanrNoNarv(r, No);
        }
            break;
            case 2:
            q=ContarNos(r);
            cout<<"a arvore tem "<<q<<"nos \n";
            break;
            case 3:
            cout<<"ingresse a chave do no a ser procurado \n";
            cin>>ch;
            PN p;
            p=buscar(ch, r);
            if(p==NULL)
            {
                cout<<"o no nao esta na arvore \n";
                
            }
            else{
                cout<<"o no esta no endereço"<<p<<"\n";
                
            }
            break;
            case 4:
            cout<<"a arvore possui os seguinte elementos: \n";
            mostrar(r);
            break;
            default:
            cout<<"opçao invalida \n";
            break;
        }
    }while(menu!=0);
    return 0;
}
