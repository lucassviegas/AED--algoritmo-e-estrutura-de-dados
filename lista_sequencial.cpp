#include <iostream>
using namespace std;
#define n 20
typedef int tipochave;
struct Registro
{
    tipochave ch;
    float preco;
};
struct Lista {
    Registro A[n+1];
    int nroElem;
};
void inicializarLista (Lista *l)
{
    l->nroElem =0;
}
int TamanhoLista (Lista *l)
{
return l->nroElem ;
}
int buscaSentinela(Lista *l, tipochave ch1)
{
    int i=0;
    l->A[l->nroElem].ch = ch1;
    while(l->A[i].ch != ch1) {i++;}
    if (i == l->nroElem) {return -1; }
    else {return i; }
}

bool inserirElemListaOrd(Lista * l, Registro reg)
{ if(l->nroElem >= n) {return false; }
else {
int pos = l->nroElem; 
while(pos > 0 && l->A[pos-1].ch > reg.ch)
 { 
l->A[pos] = l->A[pos-1]; 
pos--; 
}
l->A[pos] = reg; 
l->nroElem++;
 return true; 
}
}

void exibirLista (Lista *l)
{
int i;
cout<< "A Lista contem os seguintes elementos: \n ";
 for (i=0; i< l->nroElem; i++)
{
cout<<"o produto "<<l->A[i].ch<<"\tcusta"<<l->A[i].preco<<"\n";
 }
}
bool  excluirElemLista (tipochave ch1, Lista *l)
{
    int posElem, j;
    posElem  =buscaSentinela (l, ch1);
    if (posElem==-1) {return false;}
    else
    {
        for (j= posElem; j< l->nroElem; j++)
        { l->A[j]= l->A[j+1];}
        l->nroElem--;
    }
 return true;
}
bool contmaiorproduto(Lista * l, float pr)
{ 
    int  j=0;
    int q=0;
    for (j=0; j<l->nroElem; j++)
    {
        if (l->A[j].preco>pr)
        {
            q++;
        }
    }
    return q;
}
    
   
    
   
int main(){

Registro prod;
float pr;
Lista l1;
int a=1;
int ch, v, i;
inicializarLista(&l1);
while(a=!0){
cout << "Bem-vindo ao gerenciador da lista \n 0-Sair.\n 1-Inserir elemento.";
cout << "\n 2-Contar os elementos. \n 3-Buscar um elemento pela chave. \n 4-Exibir lista. \n 5-Removerum elemento.\n6-contagem de produtos\n";

cin >> a;
switch(a){
case 0:
return 0;
break;
case 1:

cout << "ingresse a chave:\n ";
cin >> prod.ch;
cout<<"ingresse  preco do produto";
cin>>prod.preco;
v = buscaSentinela(&l1, prod.ch);
if (v>0)
{
cout << "O cÃ³digo deste produto jÃ¡ estÃ¡ em uso\n";
}
else
{
  inserirElemListaOrd(&l1, prod);  
}
break;
case 2:
cout << "Quantia de produtos: " <<TamanhoLista(&l1)<<endl;
break;
case 3:
cout << "CÃ³digo do produto: ";
int cod;
cin >> cod;
if (buscaSentinela(&l1, cod)==0)
cout << "Produto nÃ£o estÃ¡ na lista.\n";
else
cout << "o produto estÃ¡ na lista " ;
break;
case 4:
cout << "Lista: \nCÃ³digo   |     PreÃ§o\n" ;
exibirLista(&l1);
break;
case 5:
cout << "CÃ³digo do produto a ser excluÃ­do: ";
excluirElemLista(cod, &l1);
break;
case 6:
cout<<"ingresse o preco para ver se hÃ¡ um maior";
cin>>pr;
cout<<"a quantidade de produtos com preÃ§o maior que " << pr <<"Ã©: " <<contmaiorproduto;
break;
default:
break;

}
cout << endl;
}
return 0;
}
