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

  public: FilaDinamica(); // funÃ§Ã£o criadora
  bool vazia(); // 1 vazia 0 nÃ£o vazia
  void inserir(elemento e); // push
  elemento remover(); //pop
  void mostrar();
  int gettamanho();
  bool busca(tipochave ch);
};
class PilhaDinamica {
  private: No * NoTopo;

  public: PilhaDinamica(); // funÃ§Ã£o criadora
  ~PilhaDinamica(); // funÃ§Ã£o destrutora
  bool vazia(); //funÃ§ao para saaber se pilha esta vaiza
  bool cheia(); //funÃ§ao para saber se esta cheia
  void inserir(elemento e);
  elemento remover(); //remover um elemento
  void mostrar(); //sever para imprimir o que foi inserrido
  int gettamanho(); //uma funÃ§Ã£o com um inteiro para mostraro tamanho 
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
    cout << "\n faÃ§a uma escolha \n";
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
                    cout << "nÃ£o foi possivel realizar essa operaÃ§Ã£o\n";
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
          cout << "o tamanho da fila Ã©: " << f1.gettamanho() << "\n";
          break;
        case 5:
          cout << "digite a chave do elemento a ser procurado\n";
          cin >> ch1;
          if (f1.busca(ch1) == 1) {
            cout << "o elemnto jÃ¡ estÃ¡ na fila\n";
          } else {
            cout << "o elemnto nÃ£o estÃ¡ na fila\n";
          }
          break;
        case 6:
          f1.~FilaDinamica();
          break;
        default:
          cout << "opÃ§Ã£o invalida \n";
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
                    cout << "nÃ£o foi possivel realizar essa operaÃ§Ã£o\n";
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
          cout << "o tamanho da pilha Ã©: " << p1.gettamanho() << "\n";
          break;
        case 5:
          cout << "digite a chave do elemento a ser procurado\n";
          cin >> ch1;
          if (p1.busca(ch1) == 1) {
            cout << "o elemnto jÃ¡ estÃ¡ na pilha\n";
          } else {
            cout << "o elemnto nÃ£o estÃ¡ na pilha\n";
          }
          break;
        case 6:
          p1.~PilhaDinamica();
          break;
        default:
          cout << "opÃ§Ã£o invalida \n";
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
  NoTopo = NULL; //a funÃ§Ã£o ira criar um notopo que sera deixado como nulo, asssim ele receber NULL
}
bool PilhaDinamica::vazia()
/* ira verificar se pilha esta vazia, caso esteja ela ira retornar true, caso nao esteja vazia ira retornar false*/
{
  return (NoTopo == NULL);
}
bool PilhaDinamica::cheia()
/*nessa funÃ§ao iremos tentar criar um no NoNovo, se for possivel, signiifaca que ainda ha  espaÃ§o suficiente na menoria para retornar.
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
  if (busca(e.chave) == 1) // se ele jÃ¡ estÃ¡ nÃ£o podemos inserir
  {
    cout << "o elemento com chave " << e.chave << " jÃ¡ estÃ¡ na pilha\n";
  } else {
    No * NoNovo = new No; //criaremos um novo nÃ³ com tipo no
    NoNovo -> valor = e; //ira receber um valor estrurura nÃ³
    NoNovo -> anterior = NoTopo;
    NoTopo = NoNovo;
    cout << "o elemento com chave" << e.chave << "foi inserido\n";
  }
}
elemento PilhaDinamica::remover() {
  int a;
  elemento e;
  a = vazia(); //sÃ³ poderemos remover se a pilha nÃ£o estiver vazia
  if (a == 1) // se a funÃ§Ã£o retornar 1, entÃ£o a pilha estÃ¡ vazia
  {
    cout << " NÃ£o foi possivel remover: a pilha jÃ¡ estÃ£ vazia\n";
    cout << "tente outra opÃ§Ã£o\n";
    return e;
  } else //se o retorno nÃ£o Ã© 1, entÃ£o podemos remover o elemento do topo
  {
    //criaremos um nÃ³ temporario para armazenar o endereÃ§o do topo
    No * NoTemp;
    NoTemp = NoTopo; //o endereÃ§o de memÃ³ria que estava em nÃ³ topo agora 
    //estÃ¡ tambem em NoTemp
    tipochave ch;
    ch = NoTopo -> valor.chave; //pegamos a chave do elemento que estava no topo
    NoTopo = NoTopo -> anterior; // o topo agora aponta para elemento abaixo deletamos
    delete NoTemp;
    return e; // retornamos a chave do NÃ³ que foi removido
  }
}
void PilhaDinamica::mostrar() {
  No * NoTemp;
  NoTemp = NoTopo; // comeÃ§amos no topo
  //NoTemp deverÃ¡ andar atÃ© NULL 
  cout << "os elementos da pilha sÃ£o:\n";
  cout << "{\n";
  while (NoTemp != NULL) {
    cout << NoTemp -> valor.chave << " \n";
    //cout<<NoTem->valor.OutroCampo <<"\n";
    NoTemp = NoTemp -> anterior;
  }
  cout << "} \n";
}
PilhaDinamica::~PilhaDinamica()
/*nessa funÃ§ao criaremosum no temporario */
{
  No * NoTemp;
  while (NoTopo != NULL)
  /* enquanto no tompo for diferente de NULL,pois irei comeÃ§ar desalocando do topo*/
  {
    NoTemp = NoTopo; //notemp ira receber o notopo
    NoTopo = NoTopo -> proximo; //o no topo vai para o proximo
    delete NoTemp; //
  }
}
int PilhaDinamica::gettamanho() {
  int tamanho = 0;
  No * NoTemp;
  NoTemp = NoTopo; // comeÃ§amos no topo
  //NoTemp deverÃ¡ andar atÃ© NULL 
  while (NoTemp != NULL) {
    tamanho = tamanho + 1;
    NoTemp = NoTemp -> anterior;
  }
  return tamanho;
}
bool PilhaDinamica::busca(tipochave ch) {
  No * NoTemp;
  NoTemp = NoTopo; // comeÃ§amos no topo
  //NoTemp deverÃ¡ andar atÃ© NULL 
  while (NoTemp != NULL) {
    if (NoTemp -> valor.chave == ch) {
      return true;
    }
    NoTemp = NoTemp -> anterior;
  }
  cout << "elemento nÃ£o encontrado\n";
  return false;
}
FilaDinamica::FilaDinamica() {
  inicio = NULL; // 
  fim = NULL;
}
int FilaDinamica::gettamanho() {
  int tamanho = 0;
  No * NoTemp;
  NoTemp = inicio; // comeÃ§amos no inicio da fila
  //NoTemp deverÃ¡ andar atÃ© NULL 
  while (NoTemp != NULL) {
    tamanho = tamanho + 1;
    NoTemp = NoTemp -> proximo; //passamos para o prÃ³ximo nÃ³
  }
  return tamanho;
}
void FilaDinamica::mostrar() {
  No * NoTemp;
  NoTemp = inicio; // comeÃ§amos no inicio
  //NoTemp deverÃ¡ andar atÃ© NULL 
  cout << "os elementos da fila sÃ£o:\n";
  cout << "{\n";
  while (NoTemp != NULL) {
    cout << NoTemp -> valor.chave << " \n";
    NoTemp = NoTemp -> proximo;
  }
  cout << "} \n";
}
void FilaDinamica::inserir(elemento e)
/*A funÃ§Ã£o malloc() em C++ Ã© usada para alocar o tamanho de bytes solicitado e retorna um ponteiro para o primeiro byte da memÃ³ria alocada. Um malloc( */
{
  if (busca(e.chave) == 1) {
    cout << "o elemento com chave " << e.chave << " jÃ¡ estÃ¡ na fila\n";
  } else {
    No * NoNovo;
    NoNovo = (No * ) malloc(sizeof(elemento));
    NoNovo -> valor = e;
    NoNovo -> proximo = NULL;
    if (fim == NULL) {
      inicio = NoNovo;
      fim = NoNovo;
    } else {
      fim -> proximo = NoNovo; // se jÃ¡ tem um fim o proximo dele receberÃ¡ o nÃ³ novo
      fim = fim -> proximo; //o mesmo que fim=NoNovo;
    }
    cout << "o elemento com chave" << e.chave << "foi inserido\n";
  }
}
bool FilaDinamica::busca(tipochave ch) {
  No * NoTemp;
  NoTemp = inicio; // comeÃ§amos no inicio
  //NoTemp deverÃ¡ andar atÃ© NULL 
  while (NoTemp != NULL) {
    if (NoTemp -> valor.chave == ch) {
      return true;
    }
    NoTemp = NoTemp -> proximo;
  }
  cout << "elemento nÃ£o encontrado\n";
  return false;
}
elemento FilaDinamica::remover() {
  int a;
  elemento e;
  a = vazia(); //sÃ³ poderemos remover se a fila nÃ£o estiver vazia
  if (a == 1) // se a funÃ§Ã£o retornar 1, entÃ£o a fila estÃ¡ vazia
  {
    cout << " NÃ£o foi possivel remover: a fila jÃ¡ estÃ£ vazia\n";
    cout << "tente outra opÃ§Ã£o\n";
    e.chave = -1;
    return e;
  } else //se o retorno nÃ£o Ã© 1, entÃ£o podemos remover o elemento do topo
  { //criaremos um nÃ³ temporario para armazenar o endereÃ§o 
    No * NoTemp;
    NoTemp = inicio; //o endereÃ§o de memÃ³ria que estava em nÃ³ inicio agora 
    //estÃ¡ tambem em NoTemp
    tipochave ch;
    ch = inicio -> valor.chave; //pegamos a chave do elemento que estava no inicio
    inicio = inicio -> proximo; // atualizamos o inicio com quem era o proximo
    e = NoTemp -> valor;
    delete NoTemp; //delatamos o antigo inicio
    //agora devemos saber se apagamos o Ãºltimo elementos
    if (inicio == NULL) // Perguntar se agora o inicio Ã© NULL
    {
      fim = NULL;
    } // entÃ£o o fim tambÃ©m deve apontar para NULL
    return e; // retornamos a chave do NÃ³ que foi removido
  }
}

bool FilaDinamica::vazia() {
  if (inicio == NULL) {
    return true;
  } else {
    return false;
  }
