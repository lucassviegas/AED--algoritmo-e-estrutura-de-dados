
#include <iostream>
#include<cstdlib>
#include<cstddef>
using namespace std;
typedef int tipochave;
typedef float tipopreco;
struct elemento
{
    tipochave chave;
    tipopreco preco;
    //outros campos do elemento
};
struct No // cada no possui um elemento 
{           // E o endereço de outro no.
    elemento valor;
    No *anterior; 
	No *prox;//um ponteiro para outro no
}; 

class PilhaD
{
    private:
      No *NoTopo; //um ponteiro para o No topo
                // ou seja o endereço do no topo
 
    public:
        PilhaD(); // função criadora
        //~PilhaD (); // função destrutora
        bool vazia (); // 1 vazia 0 não vazia
        void inserir (elemento e); // push
        tipochave remover(); //pop
        tipopreco removerp();
        void mostrar ();
        int gettamanho ();
        bool busca (tipochave ch);
};
class FilaD
{
    private:
      No *inicio;
	  No *fim; //Sabendo onde está o fim podemos acessar todos os Nos
    public:
        FilaD(); // função criadora
        bool vazia (); // 1 vazia 0 não vazia
        void inserir (elemento e); // push
        void inseririnicio(elemento e);
        tipochave remover(); //pop
        tipopreco removerp();
        void mostrar ();
        int gettamanho ();
        bool busca (tipochave ch);
};
int main(){
int menuPilha;
int menuFila;
int menu;
int menuRemover;
int menuRemover2;
 FilaD f1;
 PilhaD p1;
    elemento e1;
    tipochave ch1;
do{
cout<<"Digite:"<<endl;
cout<<"0 para sair."<<endl;
cout<<"1 Para gerenciar a Pilha."<<endl;
cout<<"2 Para gerenciar a Fila"<<endl;
cin>>menu;

switch(menu){
	default:	
		cout<<"Opcao Invalida"<<endl;
		break;
		
	case 0: cout<<"Fim"<<endl; 
            break;
            
    case 1:
    cout<<"faça uma escolha \n";
    do
    {
        cout<<"digite: \n";
        cout<<" 0 para terminar \n";
        cout<<" 1 para inserir um elemento \n";
        cout<<" 2 para remover um elemento \n";
        cout<<" 3 para ver todos os elementos da pilha\n";
        cout<<" 4 para ver o tamanho da pilha \n";
        cout<<" 5 para buscar por um elemento \n";
        cin>>menuPilha;
        
        switch (menuPilha)
        {
            case 0: break;
            case 1: cout<<"digite a chave do elemento a ser inserido";
                     cin>>e1.chave;
                     
                     cout<<"digite o preco do elemento que sera inserido:";
                     cin>>e1.preco;
                     
                     if(p1.busca(e1.chave)==1 || f1.busca(e1.chave)==1)
					cout<<"O elemento ja esta na pilha ou na fila."<<endl;
					
					else
					p1.inserir (e1);
					 
					break;
            case 2: cout<<"faca uma escolha:"<<endl;
			do{
            	cout<<"0 Para voltar para o menu anterior.";
				cout<<"1 Para remover permanentemente."; 
				cout<<"2 Para colocar o elemento em outra estrutura.";
				cin>>menuRemover;
				
				switch(menuRemover){
				case 0:
					cout<<"voltando ao menu anterior";
					break;
					
				case 1:
					p1.remover();
					break;
					
				case 2:
					cout<<"faca uma escolha:"<<endl;
					
					do{
						cout<<"0 para voltar para o menu anterior."<<endl; 
						cout<<"1 para colocar o elemento removido no topo da pilha."<<endl;
						cout<<"2 para colocar o elemento removido no inicio da fila."<<endl; // PILHA --> FILA FEITO.
						cin>>menuRemover2;
						
						switch(menuRemover2){ 
						case 0:
						cout<<endl<<"voltando ao menu anterior."<<endl;
						break;
						
						case 1:
						int full1;
						full1=p1.vazia();
						
						if(full1==1)
						cout<<endl<<"Nao e possivel, pois a pilha esta vazia!"<<endl;
						
						else
						cout<<endl<<"Elemento removido e colocado no topo da pilha novamente."<<endl;
						
						break;
						
						case 2:
						int full;
						full=p1.vazia();
						
						if(full==1)
						cout<<endl<<"Nao e possivel, pois a pilha esta vazia!"<<endl;
							
						else{
						cout<<endl<<"O elemento removido foi inserido no inicio da fila."<<endl;			
						e1.preco=p1.removerp();
						e1.chave=p1.remover();
						f1.inseririnicio(e1);}
							
						break;
						
						default:
						cout<<endl<<"opcao invalida!"<<endl;
						
						break;
					}
					}
					while(menuRemover2!=0);
					break;
				}
				break;
			}
			while(menuRemover!=0); 
			break;
			
            case 3:  p1.mostrar();  break;
            
            case 4: 
			cout<< "o tamanho da pilha é: " <<p1.gettamanho() <<"\n";
            break;
                     
            case 5:
			cout<<"digite a chave do elemento a ser procurado\n";
            cin>>ch1;
            
            if (p1.busca(ch1)==1) 
			 cout<<"o elemnto já está na pilha \n"; 
			 
            else  cout<<"o elemnto não está na pilha\n";
			
			 break;
			 
         default: 
		 cout<<"opção invalida \n"; 
		 break;
		 
  }}
   while(menuPilha!=0);
	break;
	
	case 2:
	cout<<"faça uma escolha \n";
	
    do
    {
        cout<<"digite: \n";
        cout<<" 0 para terminar \n";
        cout<<" 1 para inserir um elemento \n";
        cout<<" 2 para remover um elemento \n";
        cout<<" 3 para ver todos os elementos da fila\n";
        cout<<" 4 para ver o tamanho da fila \n";
        cout<<" 5 para buscar por um elemento \n";
        cin>>menuFila;
        switch (menuFila)
        {
            case 0: cout<<"voltando ao menu anterior"; break;
            
            case 1: cout<<"digite a chave do elemento a ser inserido:";
                     cin>>e1.chave;
                     cout<<"digite o preco do elemento que sera inserido:";
                     cin>>e1.preco;
                     if(p1.busca(e1.chave)==1 || f1.busca(e1.chave)==1){
					cout<<"O elemento ja esta na pilha ou na fila."<<endl;}
					else{
					f1.inserir(e1);
					}  break;
            case 2: 
			cout<<"faca uma escolha:"<<endl;
			do{
            	cout<<"0 Para voltar para o menu anterior.";
				cout<<"1 Para remover permanentemente."; 
				cout<<"2 Para colocar o elemento em outra estrutura.";
				cin>>menuRemover;
				
				switch(menuRemover){
				case 0:
					cout<<"voltando ao menu anterior";
					break;
					
				case 1:
					f1.remover();
					break;
					
				case 2:
					cout<<"faca uma escolha:"<<endl;
					do{
						cout<<"0 para voltar para o menu anterior."<<endl; 

						cout<<"1 para colocar o elemento removido no topo da pilha."<<endl;

						cout<<"2 para colocar o elemento removido no inicio da fila."<<endl;
						
						cin>>menuRemover2;
						
						switch(menuRemover2){ 
						case 0:
							cout<<endl<<"voltando ao menu anterior."<<endl;
						break;
						
						case 1:
						int full4;
						full4=f1.vazia();	
						if(full4==1)
						cout<<endl<<"Nao e possivel, pois a fila esta vazia!"<<endl;
						
						else{
							cout<<"O elemento removido foi inserido no topo da pilha."<<endl;
						e1.preco=f1.removerp();
						e1.chave=f1.remover();
						p1.inserir(e1);}
							
						break;
						
						case 2:
						int full3;
						full3=f1.vazia();
						if(full3==1)
							cout<<endl<<"Nao e possivel, pois a fila esta vazia!"<<endl;
							
						else 
						cout<<endl<<"O elemento removido foi inserido no inicio da fila."<<endl;
									
						break;
						
						default:
							cout<<endl<<"opcao invalida!"<<endl;
						break;
					}
					}while(menuRemover2!=0);
					break;
				}
				break;
			}while(menuRemover!=0); 
			break;
			
            case 3:  f1.mostrar();  break;
            
            case 4:  cout<< "o tamanho da fila é: " <<f1.gettamanho() <<"\n";
                     break;
                     
            case 5: cout<<"digite a chave do elemento a ser procurado\n";
                cin>>ch1;
                if (f1.busca(ch1)==1){  cout<<"o elemnto já está na fila\n"; }
                else { cout<<"o elemnto não está na fila\n";} break;
                
            default: cout<<"opção invalida \n"; break;
        }	
	}while(menuFila!=0);

}
}while(menu!=0);
	return 0;
}

PilhaD::PilhaD ()
{
    NoTopo=NULL; // criamos o Nó topo
    //ou seja o pohteiro para topo recebe NULL
}

bool PilhaD::vazia()
{
    if(NoTopo==NULL) {return true;}
    else { return false;}
}

void PilhaD::inserir (elemento e)
{
    if (busca (e.chave)==1) // se ele já está não podemos inserir
    {
        cout<<"o elemento com chave " <<e.chave << " já está na pilha\n";
    }
    else
    {
        No *NoNovo; //criamos um novo no tipo No
        NoNovo=(No *) malloc(sizeof(elemento)); //alocamos memoria pra ele
        //(com todos os campos da estrutura No)
        NoNovo->valor=e; // no campo valor da estrutura No
        NoNovo->anterior=NoTopo; // o anterior é o antigo topo
        NoTopo=NoNovo; // o topo é atualizado
        cout<<"o elemento com chave" <<e.chave <<"foi inserido\n";
    }
   
}



tipochave PilhaD::remover()
{
    int a;
    a=vazia(); //só poderemos remover se a pilha não estiver vazia
    
    if(a==1) // se a função retornar 1, então a pilha está vazia
    {
        cout<<" Não foi possivel remover: a pilha já estã vazia\n";
        cout<<"tente outra opção\n";
         return 0;
    }
    
    else //se o retorno não é 1, então podemos remover o elemento do topo
    {
    //criaremos um nó temporario para armazenar o endereço do topo
    No *NoTemp;
    NoTemp=NoTopo; //o endereço de memória que estava em nó topo agora
    //está tambem em NoTemp
    tipochave ch;
    ch=NoTopo->valor.chave; //pegamos a chave do elemento que estava no topo
    NoTopo=NoTopo->anterior; // o topo agora aponta para elemento abaixo deletamos
    delete NoTemp;
    return ch; // retornamos a chave do Nó que foi removido
    }
}

void PilhaD::mostrar ()
{
    No *NoTemp;
    NoTemp=NoTopo; // começamos no topo
    //NoTemp deverá andar até NULL
    cout<<"os elementos da pilha são:\n";
    cout<<"Chave           |               Preço"<<endl;
    while (NoTemp!=NULL)
    {   
        cout<<"Chave:"<<NoTemp->valor.chave<<"Preço:"<<NoTemp->valor.preco <<"\n";
        NoTemp=NoTemp->anterior;
    }
    cout<<"} \n";
}

tipopreco PilhaD::removerp()
{
    int a;
    a=vazia(); //só poderemos remover se a pilha não estiver vazia
    
    if(a==1) // se a função retornar 1, então a pilha está vazia
    {
        cout<<" Não foi possivel remover: a pilha já estã vazia\n";
        cout<<"tente outra opção\n";
         return 0;
    }
    
    else //se o retorno não é 1, então podemos remover o elemento do topo
    {
    //criaremos um nó temporario para armazenar o endereço do topo
    tipopreco p;
    p=NoTopo->valor.preco; //pegamos a chave do elemento que estava no topo
    return p; // retornamos a chave do Nó que foi removido
    }
}


int PilhaD::gettamanho ()
{
    int tamanho=0;
     No *NoTemp;
     NoTemp=NoTopo; // começamos no topo
    //NoTemp deverá andar até NULL
    while (NoTemp!=NULL)
    {
        tamanho=tamanho+1;
        NoTemp=NoTemp->anterior;
    }
    return tamanho;
}

bool PilhaD::busca (tipochave ch)
{
     No *NoTemp;
     NoTemp=NoTopo; // começamos no topo
    //NoTemp deverá andar até NULL
    while (NoTemp!=NULL)
    {
        if (NoTemp->valor.chave==ch)
        {
             return true;
        }
        NoTemp=NoTemp->anterior;
    }
    cout<<"elemento não encontrado\n";
     return false;
}

FilaD::FilaD(){
	inicio=NULL;
	fim=NULL;
}
bool FilaD::vazia()
{
    if(inicio==NULL) {return true;}
    else { return false;}
}

void FilaD::inserir (elemento e)
{
    if (busca (e.chave)==1) // se ele já está não podemos inserir
    {
        cout<<"o elemento com chave " <<e.chave << " já está na filha\n";
    }
    else
    {
        No *NoNovo; //criamos um novo nó tipo No
        NoNovo=(No *) malloc(sizeof(elemento)); //alocamos memoria pra ele
        //(com todos os campos da estrutura No)
        NoNovo->valor=e; // no campo valor da estrutura No
        NoNovo->prox=NULL; // o anterior é o antigo topo
        if(fim==NULL){
        inicio=NoNovo;
		fim=NoNovo;   
		}
		else{
			fim->prox=NoNovo;
			fim=fim->prox;
		}
   cout<<"o elemento com chave" <<e.chave <<"foi inserido\n";
}
}

void FilaD::inseririnicio(elemento e)
{
    if (busca (e.chave)==1) // se ele já está não podemos inserir
    {
        cout<<"o elemento com chave " <<e.chave << " já está na fila\n";
    }
    else
    {		//no fila== no novo
        No *NoNovo; //criamos um novo nó tipo No
        NoNovo=(No *) malloc(sizeof(elemento)); //alocamos memoria pra ele
        //(com todos os campos da estrutura No)
        NoNovo->valor=e; // no campo valor da estrutura No
        NoNovo->prox=NULL; // o anterior é o antigo topo
        if(fim==NULL){
        inicio=NoNovo;
		fim=NoNovo;   
		} // fila inicio fim
		else{
			NoNovo->prox=inicio;
			inicio=NoNovo;
		}
   cout<<"o elemento com chave" <<e.chave <<"foi inserido\n";
}
}

tipopreco FilaD::removerp()
{
    int a;
    a=vazia(); //só poderemos remover se a pilha não estiver vazia
    if(a==1) // se a função retornar 1, então a pilha está vazia
    {
        cout<<" Não foi possivel remover: a pilha já estã vazia\n";
        cout<<"tente outra opção\n";
         return 0;
    }
    else //se o retorno não é 1, então podemos remover o elemento do topo
    {
    //criaremos um nó temporario para armazenar o endereço do topo
    tipopreco p;
    p=inicio->valor.preco; //pegamos a chave do elemento que estava no topo
    return p; // retornamos a chave do Nó que foi removido
    }
}

tipochave FilaD::remover()
{
    int a;
    a=vazia(); //só poderemos remover se a pilha não estiver vazia
    if(a==1) // se a função retornar 1, então a pilha está vazia
    {
        cout<<" Não foi possivel remover: a fila já estã vazia\n";
        cout<<"tente outra opção\n";
         return 0;
    }
    else //se o retorno não é 1, então podemos remover o elemento do topo
    {
    //criaremos um nó temporario para armazenar o endereço do topo
    No *NoTemp;
    NoTemp=inicio; //o endereço de memória que estava em nó topo agora
    //está tambem em NoTemp
    tipochave ch;
    ch=inicio->valor.chave; //pegamos a chave do elemento que estava no topo
    inicio=inicio->prox; // o topo agora aponta para elemento abaixo deletamos
    delete NoTemp;
	if(inicio==NULL){
	fim=NULL;
}
	return ch; // retornamos a chave do Nó que foi removido
	}
}


void FilaD::mostrar ()
{
    No *NoTemp;
    NoTemp=inicio; // começamos no topo
    //NoTemp deverá andar até NULL
    cout<<"os elementos da fila são:\n";
    cout<<"{\n";
    while (NoTemp!=NULL)
    {
    	cout<<"Chave:"<<NoTemp->valor.chave<<"Preço:"<<NoTemp->valor.preco <<"\n";
        NoTemp=NoTemp->prox;
    }
    cout<<"} \n";
}

int FilaD::gettamanho ()
{
    int tamanho=0;
     No *NoTemp;
     NoTemp=inicio;
    while (NoTemp!=NULL)
    {
        tamanho=tamanho+1;
        NoTemp=NoTemp->prox;
    }
    return tamanho;
}

bool FilaD::busca (tipochave ch)
{
     No *NoTemp;
     NoTemp=inicio; // começamos no topo
    //NoTemp deverá andar até NULL
    while (NoTemp!=NULL)
    {
        if (NoTemp->valor.chave==ch)
        {
             return true;
        }
        NoTemp=NoTemp->prox;
    }
    cout<<"elemento não encontrado\n";
     return false;
}


