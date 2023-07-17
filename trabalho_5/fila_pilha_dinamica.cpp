#include<iostream>
#include<cstdlib>
#include<cstddef>
using namespace std;
typedef int tipochave;
struct elemento {
  tipochave chave;
  float preco;
  //irei guardar um numero real
};
struct No {
  elemento valor;
  No * proximo;
  No * anterior;
};
class FilaDinamica {
  private: No * inicio; //um ponteiro para o inicio
  No * fim; //um ponteiro para o final da fila         

  public: FilaDinamica(); // função criadora
  bool vazia(); // 1 vazia 0 não vazia
  void inserir(elemento e); // push
  elemento remover(); //pop
  void mostrar();
  int gettamanho();
  bool busca(tipochave ch);
};
class PilhaDinamica {
  private: No * NoTopo;

  public: PilhaDinamica(); // função criadora
  ~PilhaDinamica(); // função destrutora
  bool vazia(); //funçao para saaber se pilha esta vaiza
  bool cheia(); //funçao para saber se esta cheia
  void inserir(elemento e);
  elemento remover(); //remover um elemento
  void mostrar(); //sever para imprimir o que foi inserrido
  int gettamanho(); //uma função com um inteiro para mostraro tamanho 
  bool busca(tipochave ch);
};
int main() {
  PilhaDinamica p1;
  FilaDinamica f1;
  elemento e1;
  tipochave ch1;
  int menu;
  int menu1;
  int menu2;
  int menu3;
  int menu4;
  int menu5;
  while (true) {
    cout << "================================================\n";
    cout << "\n faça uma escolha \n";
    cout << "\n digite 0 para sair do programa\n";
    cout << "\n digite 1 para usar a pilha   \n";
    cout << "\n digite 2 para usar a fila    \n";
    cout << "=================================================\n";
    cin >> menu1;
    switch (menu1) {
    case 0:
      return 0;
      break;
    case 1:
      do {
        cout << "================================================\n";
        cout << "digite: \n";
        cout << " 0 para terminar \n";
        cout << " 1 para inserir um elemento \n";
        cout << " 2 para remover um elemento \n";
        cout << " 3 para ver todos os elementos da fila\n";
        cout << " 4 para ver o tamanho da fila \n";
        cout << " 5 para buscar por um elemento \n";
        cout << " 6 para destrir a fila \n";
        cout << "=================================================\n";
        cin >> menu;
        switch (menu) {
        case 0:
          cout << "The End\n";
          break;
        case 1:
          cout << "digite a chave do elemento a ser inserido";
          cin >> e1.chave;
          cout << "digite o preco do elemento\n";
          cin >> e1.preco;
          f1.inserir(e1);
          break;
        case 2:
          do {
            cout << "=================================================\n";
            cout << "0 Para voltar para o menu anterior \n";
            cout << "1 Para remover permanentemente \n";
            cout << "2 Para colocar o elemento em outra estrutura \n";
            cout << "=================================================\n";
            cin >> menu2;
            switch (menu2) {
            case 0:
              cout << "the end";
              break;
            case 1:
              f1.remover();
              break;
            case 2:
              do {
                cout << "=================================================\n";
                cout << "0 Para voltar para o menu anterior \n";
                cout << "1 para colocar o elemento removido no topo da pilha \n";
                cout << "2 para colocar o elemento removido no inicio da fila.  \n";
                cout << "=================================================\n";
                cin >> menu3;
                switch (menu3) {
                case 0:
                  cout << "the end";
                  break;
                case 1:
                  elemento e2;
                  e2 = f1.remover();
                  if (e2.chave == -1) {
                    cout << "não foi possivel realizar essa operação\n";
                  } else {
                    p1.inserir(e2);
                  }
                  break;
                case 2:
                  e2 = f1.remover();
                  if (e2.chave != -1) {
                    f1.inserir(e2);
                  }
                  break;
                default:
                  break;
                }
              } while (menu3 != 0);
            }
          } while (menu2 != 0);

          break;
        case 3:
          f1.mostrar();
          break;
        case 4:
          cout << "o tamanho da fila é: " << f1.gettamanho() << "\n";
          break;
        case 5:
          cout << "digite a chave do elemento a ser procurado\n";
          cin >> ch1;
          if (f1.busca(ch1) == 1) {
            cout << "o elemnto já está na fila\n";
          } else {
            cout << "o elemnto não está na fila\n";
          }
          break;
        case 6:
          f1.~FilaDinamica();
          break;
        default:
          cout << "opção invalida \n";
          break;
        }
      } while (menu != 0);
      break;
    case 2:
      do {
        cout << "=================================================\n";
        cout << "digite: \n";
        cout << " 0 para terminar \n";
        cout << " 1 para inserir um elemento \n";
        cout << " 2 para remover um elemento \n";
        cout << " 3 para ver todos os elementos da pilha\n";
        cout << " 4 para ver o tamanho da pilha \n";
        cout << " 5 para buscar por um elemento \n";
        cout << " 6 para destrir a pilha \n";
        cout << "=================================================\n";
        cin >> menu;
        switch (menu) {
        case 0:
          cout << "The End\n";
          break;
        case 1:
          cout << "digite a chave do elemento a ser inserido";
          cout << "digite a chave do elemento a ser inserido";
          cin >> e1.chave;
          cout << "digite o preco do elemento\n";
          cin >> e1.preco;
          p1.inserir(e1);
          break;
        case 2:
          do {
            cout << "=================================================\n";
            cout << "0 Para voltar para o menu anterior";
            cout << "1 Para remover permanentemente n/";
            cout << "2 Para colocar o elemento em outra estrutura /n";
            cout << "=================================================\n";
            cin >> menu4;
            switch (menu4) {
            case 0:
              cout << "the end";
              break;
            case 1:
              p1.remover();
              break;
            case 2:
              do {
                cout << "=================================================\n";
                cout << "0 Para voltar para o menu anterior";
                cout << "1 para colocar o elemento removido no topo da pilha \n";
                cout << "2 para colocar o elemento removido no inicio da fila. \n";
                cout << "=================================================\n";
                cin >> menu5;
                switch (menu5) {
                case 0:
                  cout << "the end";
                  break;
                case 1:
                  elemento e3;
                  e3 = p1.remover();
                  if (e3.chave == -1) {
                    cout << "não foi possivel realizar essa operação\n";
                  } else {
                    f1.inserir(e3);
                  }
                  break;
                case 2:
                  e3 = f1.remover();
                  if (e3.chave != -1) {
                    f1.inserir(e3);
                  }
                  break;
                default:
                  break;
                }
              } while (menu5 != 0);
            }
          } while (menu4 != 0);
          break;
        case 3:
          p1.mostrar();
          break;
        case 4:
          cout << "o tamanho da pilha é: " << p1.gettamanho() << "\n";
          break;
        case 5:
          cout << "digite a chave do elemento a ser procurado\n";
          cin >> ch1;
          if (p1.busca(ch1) == 1) {
            cout << "o elemnto já está na pilha\n";
          } else {
            cout << "o elemnto não está na pilha\n";
          }
          break;
        case 6:
          p1.~PilhaDinamica();
          break;
        default:
          cout << "opção invalida \n";
          break;
        }

      } while (menu != 0);
      break;
    case 3:
    default:
      break;
    }
  }
  return 0;
}
PilhaDinamica::PilhaDinamica() {
  NoTopo = NULL; //a função ira criar um notopo que sera deixado como nulo, asssim ele receber NULL
}
bool PilhaDinamica::vazia()
/* ira verificar se pilha esta vazia, caso esteja ela ira retornar true, caso nao esteja vazia ira retornar false*/
{
  return (NoTopo == NULL);
}
bool PilhaDinamica::cheia()
/*nessa funçao iremos tentar criar um no NoNovo, se for possivel, signiifaca que ainda ha  espaço suficiente na menoria para retornar.
se for possivel ele ira retornar falso, caso nao seja possivel ira retornar true, entao signifa que esta cheio
novos nos iremos criar com new por que nele podemos usar o delete.
o try catch:tente fazer esse daqui,se conseguir fazer irar retonar o que esta dentro do cochete.
*/
{
  No * NoNovo;
  try {
    NoNovo = new No;
    delete NoNovo;
    return false;
  } catch (bad_alloc exeption) {
    return true;
  }
}
void PilhaDinamica::inserir(elemento e) {
  if (busca(e.chave) == 1) // se ele já está não podemos inserir
  {
    cout << "o elemento com chave " << e.chave << " já está na pilha\n";
  } else {
    No * NoNovo = new No; //criaremos um novo nó com tipo no
    NoNovo -> valor = e; //ira receber um valor estrurura nó
    NoNovo -> anterior = NoTopo;
    NoTopo = NoNovo;
    cout << "o elemento com chave" << e.chave << "foi inserido\n";
  }
}
elemento PilhaDinamica::remover() {
  int a;
  elemento e;
  a = vazia(); //só poderemos remover se a pilha não estiver vazia
  if (a == 1) // se a função retornar 1, então a pilha está vazia
  {
    cout << " Não foi possivel remover: a pilha já estã vazia\n";
    cout << "tente outra opção\n";
    return e;
  } else //se o retorno não é 1, então podemos remover o elemento do topo
  {
    //criaremos um nó temporario para armazenar o endereço do topo
    No * NoTemp;
    NoTemp = NoTopo; //o endereço de memória que estava em nó topo agora 
    //está tambem em NoTemp
    tipochave ch;
    ch = NoTopo -> valor.chave; //pegamos a chave do elemento que estava no topo
    NoTopo = NoTopo -> anterior; // o topo agora aponta para elemento abaixo deletamos
    delete NoTemp;
    return e; // retornamos a chave do Nó que foi removido
  }
}
void PilhaDinamica::mostrar() {
  No * NoTemp;
  NoTemp = NoTopo; // começamos no topo
  //NoTemp deverá andar até NULL 
  cout << "os elementos da pilha são:\n";
  cout << "{\n";
  while (NoTemp != NULL) {
    cout << NoTemp -> valor.chave << " \n";
    //cout<<NoTem->valor.OutroCampo <<"\n";
    NoTemp = NoTemp -> anterior;
  }
  cout << "} \n";
}
PilhaDinamica::~PilhaDinamica()
/*nessa funçao criaremosum no temporario */
{
  No * NoTemp;
  while (NoTopo != NULL)
  /* enquanto no tompo for diferente de NULL,pois irei começar desalocando do topo*/
  {
    NoTemp = NoTopo; //notemp ira receber o notopo
    NoTopo = NoTopo -> proximo; //o no topo vai para o proximo
    delete NoTemp; //
  }
}
int PilhaDinamica::gettamanho() {
  int tamanho = 0;
  No * NoTemp;
  NoTemp = NoTopo; // começamos no topo
  //NoTemp deverá andar até NULL 
  while (NoTemp != NULL) {
    tamanho = tamanho + 1;
    NoTemp = NoTemp -> anterior;
  }
  return tamanho;
}
bool PilhaDinamica::busca(tipochave ch) {
  No * NoTemp;
  NoTemp = NoTopo; // começamos no topo
  //NoTemp deverá andar até NULL 
  while (NoTemp != NULL) {
    if (NoTemp -> valor.chave == ch) {
      return true;
    }
    NoTemp = NoTemp -> anterior;
  }
  cout << "elemento não encontrado\n";
  return false;
}
FilaDinamica::FilaDinamica() {
  inicio = NULL; // 
  fim = NULL;
}
int FilaDinamica::gettamanho() {
  int tamanho = 0;
  No * NoTemp;
  NoTemp = inicio; // começamos no inicio da fila
  //NoTemp deverá andar até NULL 
  while (NoTemp != NULL) {
    tamanho = tamanho + 1;
    NoTemp = NoTemp -> proximo; //passamos para o próximo nó
  }
  return tamanho;
}
void FilaDinamica::mostrar() {
  No * NoTemp;
  NoTemp = inicio; // começamos no inicio
  //NoTemp deverá andar até NULL 
  cout << "os elementos da fila são:\n";
  cout << "{\n";
  while (NoTemp != NULL) {
    cout << NoTemp -> valor.chave << " \n";
    NoTemp = NoTemp -> proximo;
  }
  cout << "} \n";
}
void FilaDinamica::inserir(elemento e)
/*A função malloc() em C++ é usada para alocar o tamanho de bytes solicitado e retorna um ponteiro para o primeiro byte da memória alocada. Um malloc( */
{
  if (busca(e.chave) == 1) {
    cout << "o elemento com chave " << e.chave << " já está na fila\n";
  } else {
    No * NoNovo;
    NoNovo = (No * ) malloc(sizeof(elemento));
    NoNovo -> valor = e;
    NoNovo -> proximo = NULL;
    if (fim == NULL) {
      inicio = NoNovo;
      fim = NoNovo;
    } else {
      fim -> proximo = NoNovo; // se já tem um fim o proximo dele receberá o nó novo
      fim = fim -> proximo; //o mesmo que fim=NoNovo;
    }
    cout << "o elemento com chave" << e.chave << "foi inserido\n";
  }
}
bool FilaDinamica::busca(tipochave ch) {
  No * NoTemp;
  NoTemp = inicio; // começamos no inicio
  //NoTemp deverá andar até NULL 
  while (NoTemp != NULL) {
    if (NoTemp -> valor.chave == ch) {
      return true;
    }
    NoTemp = NoTemp -> proximo;
  }
  cout << "elemento não encontrado\n";
  return false;
}
elemento FilaDinamica::remover() {
  int a;
  elemento e;
  a = vazia(); //só poderemos remover se a fila não estiver vazia
  if (a == 1) // se a função retornar 1, então a fila está vazia
  {
    cout << " Não foi possivel remover: a fila já estã vazia\n";
    cout << "tente outra opção\n";
    e.chave = -1;
    return e;
  } else //se o retorno não é 1, então podemos remover o elemento do topo
  { //criaremos um nó temporario para armazenar o endereço 
    No * NoTemp;
    NoTemp = inicio; //o endereço de memória que estava em nó inicio agora 
    //está tambem em NoTemp
    tipochave ch;
    ch = inicio -> valor.chave; //pegamos a chave do elemento que estava no inicio
    inicio = inicio -> proximo; // atualizamos o inicio com quem era o proximo
    e = NoTemp -> valor;
    delete NoTemp; //delatamos o antigo inicio
    //agora devemos saber se apagamos o último elementos
    if (inicio == NULL) // Perguntar se agora o inicio é NULL
    {
      fim = NULL;
    } // então o fim também deve apontar para NULL
    return e; // retornamos a chave do Nó que foi removido
  }
}

bool FilaDinamica::vazia() {
  if (inicio == NULL) {
    return true;
  } else {
    return false;
  }
}
