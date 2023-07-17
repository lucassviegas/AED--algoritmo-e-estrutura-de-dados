#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Produto {
  int codigo;
  float preco;
};

bool buscaProdutoNaPilha(stack < Produto > pilha, int codigo) {
  stack < Produto > temp = pilha;
  while (!temp.empty()) {
    if (temp.top().codigo == codigo) {
      return true;
    }
    temp.pop();
  }
  return false;
}

bool buscaProdutoNaFila(queue < Produto > fila, int codigo) {
  queue < Produto > temp = fila;
  while (!temp.empty()) {
    if (temp.front().codigo == codigo) {
      return true;
    }
    temp.pop();
  }
  return false;
}

int main() {
  stack < Produto > pilha;
  queue < Produto > fila;
  int opcao1, opcao2, opcao3, opcao4;
  Produto produto;

  do {
    cout << "Menu principal: \n";
    cout << "0 para sair.\n";
    cout << "1 para gerenciar a Pilha.\n";
    cout << "2 para gerenciar a Fila.\n";
    cout << "Escolha uma opcao: ";
    cin >> opcao1;

    if (opcao1 == 1) {
      do {
        cout << "Menu Pilha: \n";
        cout << "0 para voltar para o menu anterior \n";
        cout << "1 para inserir um elemento \n";
        cout << "2 para remover um elemento \n";
        cout << "3 para ver todos os elementos \n";
        cout << "4 para ver o tamanho da estrutura\n";
        cout << "5 para buscar por um elemento \n";
        cout << "Escolha uma opcao: ";
        cin >> opcao2;

        switch (opcao2) {
        case 0:
          break;
        case 1:
          cout << "Insira o codigo do produto: ";
          cin >> produto.codigo;
          if (buscaProdutoNaPilha(pilha, produto.codigo) || buscaProdutoNaFila(fila, produto.codigo)) {
            cout << "Esse produto ja esta em outra estrutura!\n";
          } else {
            cout << "Insira o preco do produto: ";
            cin >> produto.preco;
            pilha.push(produto);
            cout << "Produto inserido com sucesso!\n";
          }
          break;
        case 2:
          if (pilha.empty()) {
            cout << "A pilha está vazia!\n";
          } else {
            Produto removido = pilha.top();
            do {
              cout << "Menu Remover elemento: \n";
              cout << "0 para voltar para o menu anterior.\n";
              cout << "1 para remover permanentemente.\n";
              cout << "2 para colocar o elemento em outra estrutura.\n";
              cout << "Escolha uma opcao: ";
              cin >> opcao3;
              switch (opcao3) {
              case 0:
                break;
              case 1:
                pilha.pop();
                cout << "Produto removido permanentemente: " << removido.codigo << " - " << removido.preco << endl;
                break;
              case 2:
                do {
                  cout << "Menu Colocar em outra estrutura: \n";
                  cout << "0 para voltar para o menu anterior.\n";
                  cout << "1 para colocar o elemento removido no topo da pilha.\n";
                  cout << "2 para colocar o elemento removido no inicio da fila.\n";
                  cout << "Escolha uma opcao: ";
                  cin >> opcao4;

                  switch (opcao4) {
                  case 0:
                    break;

                  case 1:
                    if (buscaProdutoNaPilha(pilha, removido.codigo)) {
                      cout << "Esse produto ja esta na pilha!\n";
                    } else {
                      pilha.push(removido);
                      cout << "Produto inserido no topo da pilha!\n";
                    }

                    break;

                  case 2:
                    if (buscaProdutoNaFila(fila, removido.codigo)) {
                      cout << "Esse produto ja esta na fila!\n";
                    } else {
                      fila.push(removido);
                      cout << "Produto inserido no inicio da fila!\n";
                    }
                    break;
                  default:
                    cout << "Opcao invalida!\n";
                  }
                } while (opcao4 != 0);
                break;
              default:
                cout << "Opcao invalida!\n";
              }
            } while (opcao3 != 0);
          }
          break;
        case 3:
          if (pilha.empty()) {
            cout << "A pilha esta vazia!\n";
          } else {
            cout << "Produtos na pilha:\n";
            stack < Produto > temp = pilha;
            while (!temp.empty()) {
              cout << temp.top().codigo << " - " << temp.top().preco << endl;
              temp.pop();
            }
          }
          break;
        case 4:
          cout << "Tamanho da pilha: " << pilha.size() << endl;
          break;
        case 5:
          cout << "Insira o codigo do produto a ser buscado: ";
          int codigo;
          cin >> codigo;
          if (buscaProdutoNaPilha(pilha, codigo)) {
            cout << "Produto encontrado na Pilha.\n";
          } else {
            cout << "Produto não encontrado na Pilha.\n";
          }
          break;
        default:
          cout << "Opcao invalida!\n";
        }
      } while (opcao2 != 0);
    } else if (opcao1 == 2) {
      do {
        cout << "Menu Fila: \n";
        cout << "0 para voltar para o menu anterior \n";
        cout << "1 para inserir um elemento \n";
        cout << "2 para remover um elemento \n";
        cout << "3 para ver todos os elementos \n";
        cout << "4 para ver o tamanho da estrutura\n";
        cout << "5 para buscar por um elemento \n";
        cout << "Escolha uma opcao: ";
        cin >> opcao2;
        switch (opcao2) {
        case 0:
          break;
        case 1:
          cout << "Insira o codigo do produto: ";
          cin >> produto.codigo;
          if (buscaProdutoNaPilha(pilha, produto.codigo) || buscaProdutoNaFila(fila, produto.codigo)) {
            cout << "Esse produto ja esta em outra estrutura!\n";
          } else {
            cout << "Insira o preco do produto: ";
            cin >> produto.preco;
            fila.push(produto);
            cout << "Produto inserido com sucesso!\n";
          }
          break;
        case 2:
          if (fila.empty()) {
            cout << "A fila esta vazia!\n";
          } else {
            Produto removido = fila.front();
            do {
              cout << "Menu Remover elemento: \n";
              cout << "0 para voltar para o menu anterior.\n";
              cout << "1 para remover permanentemente.\n";
              cout << "2 para colocar o elemento em outra estrutura.\n";
              cout << "Escolha uma opcao: ";
              cin >> opcao3;

              switch (opcao3) {
              case 0:
                break;
              case 1:
                fila.pop();
                cout << "Produto removido permanentemente: " << removido.codigo << " - " << removido.preco << endl;
                break;
              case 2:
                do {
                  cout << "Menu Colocar em outra estrutura: \n";
                  cout << "0 para voltar para o menu anterior.\n";
                  cout << "1 para colocar o elemento removido no topo da pilha.\n";
                  cout << "2 para colocar o elemento removido no inicio da fila.\n";
                  cout << "Escolha uma opcao: ";
                  cin >> opcao4;

                  switch (opcao4) {
                  case 0:
                    break;
                  case 1:
                    if (buscaProdutoNaPilha(pilha, removido.codigo)) {
                      cout << "Esse produto ja esta na pilha!\n";
                    } else {
                      pilha.push(removido);
                      cout << "Produto inserido no topo da pilha!\n";
                    }
                    break;
                  case 2:
                    if (buscaProdutoNaFila(fila, removido.codigo)) {
                      cout << "Esse produto ja esta na fila!\n";
                    } else {
                      fila.push(removido);
                      cout << "Produto inserido no inicio da fila!\n";
                    }
                    break;
                  default:
                    cout << "Opcao invalida!\n";
                  }
                } while (opcao4 != 0);
                break;
              default:
                cout << "Opcao invalida!\n";
              }
            } while (opcao3 != 0);
          }
          break;
        case 3:
          if (fila.empty()) {
            cout << "A fila esta vazia!\n";
          } else {
            cout << "Produtos na fila:\n";
            queue < Produto > temp = fila;
            while (!temp.empty()) {
              cout << temp.front().codigo << " - " << temp.front().preco << endl;
              temp.pop();
            }
          }
          break;
        case 4:
          cout << "Tamanho da fila: " << fila.size() << endl;
          break;
        case 5:
          cout << "Insira o codigo do produto a ser buscado: ";
          int codigo;
          cin >> codigo;
          if (buscaProdutoNaFila(fila, codigo)) {
            cout << "Produto encontrado na Fila.\n";
          } else {
            cout << "Produto não encontrado na Fila.\n";
          }
          break;
        default:
          cout << "Opcao invalida!\n";
        }
      } while (opcao2 != 0);
    } else if (opcao1 != 0) {
      cout << "Opcao invalida!\n";
    }
  } while (opcao1 != 0);
  return 0;
}