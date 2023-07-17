#include <iostream>
#include<cstdlib>
#include<cstddef>
using namespace std;
#define max  50
typedef int tipochave;
struct registro {
  tipochave chave;
  float preco;
};
struct lista {
  registro a [max];
  int nroElem;
};
void inicializarlista(lista * l, registro reg, int i) {
  int j;
  if (l->nroElem == max || (i < 0) || (i > l-> nroElem))
    for (j = l -> nroElem; j > i; j++)
      l -> a[j - 1];
      l -> a[i] = reg;
}
bool inserirElemlista(lista * l, registro reg, int i) {
  int j;
  if ((l -> nroElem == max) || (i < 0) || (i > l -> nroElem))
    {return false;}
  for (j = l -> nroElem; j > i; j--)
    l -> a[j] = l -> a[j - 1];
    l -> a[i] = reg;
    l -> nroElem++;
    return true;
}
void exibirlista(lista * l) {
  int i;
  cout << "lista: ";
  for (i = 0; i < l ->nroElem; i++) 
    cout << "%i", l-> a[i].chave;
    cout << "  ";
}
int tamanholista(lista * l) {
  return l -> nroElem;
}
bool buscaSequencial(lista * l, tipochave ch) {
  int i = 0;
  while (i < l -> nroElem) {
    if (ch == l -> a[i].chave) 
      return i;
     else i++;
  }
return -1;
}
int buscasentinela(lista *l,tipochave ch)
{
    int i=0;
    l->a[l->nroElem].chave=ch;
    while(l->a[i].chave!=ch)
    i++;
    if(i==l->nroElem)
    return -1;
    else return i;
}
int buscabinaria(lista * l, tipochave ch) 
{
  int esquerda, direita, meio;
  esquerda = 0;
  direita = 0;
  direita = l -> nroElem - 1;
  while(esquerda<=direita){
      if(l->a[meio].chave==ch)return meio;
      else{
          if(l->a[meio].chave<ch)esquerda=meio+1;
          else direita=meio-1;
      }
  }
 return -1;
}
bool inserirElemlistaOrdenada(lista *l, registro reg)
{
  if (l -> nroElem >= max)
  return false;
    int pos = l -> nroElem;
    while (pos > 0 && l -> a[pos - 1].chave > reg.chave)
    {
        l->a[pos]=l->a[pos-1];
        pos--;
        
    }
    l -> a[pos] = reg;
    l -> nroElem++;
    return true;
}

bool excluirElemlista(tipochave ch, lista * l)
{
  int pos, j;
  pos = buscabinaria(l, ch);
  if (pos == -1) 
    return false;
  for (j = pos; j < l -> nroElem - 1; j++) 
    l -> a[j] = l -> a[j + 1];
    l -> nroElem--;
    return true;
}

int main()
    {
  lista l1;
  registro pr1;
  tipochave ch;
  int menu1;
  cout << "faça uma escolha\n";
  do {
    cout << "digite: \n";
    cout << "0 para terminar \n";
    cout << "1 para inserir um produto \n";
    cout << "2 para contar a quantidade de prtodutos \n";
    cout << "3 para mostrar os produtos na lista \n";
    cout << "4 para para ordenar a lista usando o primeiro algoritmo \n";
    cout << "5 para fazer uma  busca sequencial\n";
    cout << "6 para fazer uma busca binaria pela chave \n";
    cout << "7 para eliminar um produto da lista \n";
    cin>>menu1;
    switch (menu1) 
    {
    case 0:
      cout << "fim";
      break;
    case 1:
      cout << "digite a chave do produto a ser inserido";
      cin >> pr1.chave;
      cout << "digite o preco do elemento\n";
      cin >> pr1.preco;
      inserirElemlista(&l1, pr1, 0);
      break;
    case 2:
      cout << "o tamanho do produto e: " << tamanholista(&l1) << "\n";
      break;
    case 3:
    cout<<inserirElemlistaOrdenada(&l1, pr1);
      break;
    case 4:
      exibirlista(&l1);
      break;
    case 5:
      cout << "digite a chave do elemento a ser procurado\n";
      cin >> ch;
      if (buscaSequencial(&l1,ch) == 1) {
        cout << "o elemento foi encontardo com sucesso";
      }
      break;
    case 6:
      cout << "digite a vhave do elemento para ser feito um busca binaria por ele";
      cin >> ch;
      if (buscabinaria(&l1, ch) == 1) {
        cout << "o resulatdo da busca bianria e";
      }
      break;
      case 7:
      excluirElemlista (ch,&l1);
      break;
    default:
      cout << "opçao invalida \n";
      break;
    }
  } while (menu1!=0);

  return 0;
}