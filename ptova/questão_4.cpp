#include<iostream>

#include<cstdlib>

#include<cstddef>

#define size 50
using namespace std;

typedef int tipochave;
struct elemento {
  tipochave chave;
  float preco;
};
class fila {
  private: int primeiro;
  int ultimo;
  elemento * dado;

  public: fila(); //construtor;
  bool filavazia();
  bool filacheia();
  void inserir(elemento e);
  tipochave remover();
  void imprimir();
  int gettamanho();
  bool buscar(tipochave ch);

};
fila::fila() //construtora
{
  primeiro = 0;
  ultimo = 0;
  dado = new elemento[size];

}
bool fila::filavazia() {
  return (primeiro == ultimo);
}
bool fila::filacheia() {
  if (ultimo - primeiro == size) {
    return true;
  } else {
    return false;
  }
}
void fila::inserir(elemento e) {
  int a;
  a = filacheia();
  if (a == 1) {
    cout << "a fila ja esta cheia\n";

  } else {
    if (buscar(e.chave) == 1) {
      cout << "o elemento com chave " << e.chave << "ja esta na fila\n";
    } else {
      int posicao;
      posicao = ultimo % size;
      dado[posicao] = e;
      ultimo = ultimo++;
    }
  }

}
tipochave fila::remover() {
  int a;
  a = filavazia();
  if (a == 1) {
    cout << "nao foi possivel remover: a fila ja esta vazia\n";
    return 0;
  } else {
    cout << "foi removido com sucesso\n";
    return dado[primeiro % size].chave;
    primeiro - 1;
  }
}
void fila::imprimir() {
  cout << "fila: ";
  int i;
  for (i = primeiro; i < ultimo; i++) {
    cout << i << endl << primeiro;

  }
  cout << "\n";
}
bool fila::buscar(tipochave ch) {
  int i;
  for (int i = primeiro; i < ultimo; i++) {
    if (dado[i % size].chave == ch) {
      return true;
    }

  }
  return false;
}
int fila::gettamanho() {
  return (ultimo - primeiro);
}
int main() {
  fila fila1;
  int menu;
  tipochave ch1;
  elemento e1;
  cout << "faça uma escolha para iniciar\n";
  do {
    cout << "digite: \n";
    cout << "0 para terminar \n";
    cout << "1 para inserir o elemento que deseja \n";
    cout << "2 para imprimir a quantidade de produtos \n";
    cout << "3 para procurar um elemento pela chave \n";
    cout << "4 para ver o tamanho da fila \n";
    cout << "5 para remover um produto da fila \n";
    cin >> menu;
    switch (menu) {
    case 0:
      cout << "fim\n";
      break;
    case 1:
      cout << "digite a chave do elemento a ser inserido";
      cin >> e1.chave;
      cout << "digite o preco do elemento\n";
      cin >> e1.preco;
      fila1.inserir(e1);
      break;
    case 2:
      fila1.imprimir();
      break;
    case 3:
      cout << "digite a chave do elemento a ser procurado\n";
      cin >> ch1;
      if (fila1.buscar(ch1) == 1) {
        cout << "o elemnto jÃ¡ estÃ¡ na pilha\n";
      } else {
        cout << "o elemnto nÃ£o estÃ¡ na pilha\n";
      }
      break;
    case 4:
      cout << "o tamanho da fila : " << fila1.gettamanho() << "\n";
      break;
    case 5:
      cout << fila1.remover() << "\n";
      break;
    default:
      break;

    }
  } while (menu != 0);
  return 0;
}

