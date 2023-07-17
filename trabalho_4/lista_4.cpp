#include <iostream>
#include <cstdlib>
using namespace std;

//grupo envolvido na realização do código: Frederico, Enzo, Lucas

struct Registro{
	int chave;
	float preco;
};

struct Elemento{
	Elemento* prox;
	Registro reg;
};

struct Lista{
	Elemento* inicio;
};

typedef Elemento* PONT;


void inicializarLista (Lista *I){
I -> inicio = NULL;
}

int tamanho (Lista *l){
PONT end = l ->inicio;
int tam = 0;
while (end!= NULL){
tam++;
end=end->prox;
}
return tam;
}

void exibe (Lista *l){
PONT end = l->inicio;
int x=0;
while (end!=NULL){
cout<<"--PRODUTO "<<x+1<<"--\n"<<"chave: "<<end->reg.chave <<"\npreco: "<<end->reg.preco<<'\n'<<'\n'<<'\n';
x++;
end=end->prox;
}
}

PONT buscaseq (Lista *l, int ch,int* pt){
PONT pos = l->inicio;
while(pos!=NULL){
if (pos->reg.chave==ch)
return pos;
*pt+=1;
pos=pos->prox;
}
return NULL;
}

PONT buscaord (Lista *l, int ch){
PONT pos = l->inicio;
while (pos!=NULL&&pos->reg.chave<ch){
if(pos!=NULL&&pos->reg.chave==ch)
return pos;
pos=pos->prox;

}
return NULL;
}

PONT buscaseqexc (Lista** l, int ch, Elemento** ant){
   *ant = NULL;
    PONT atual = (*l)->inicio;
   
    while((atual != NULL) && (atual->reg.chave<ch))
    {
        *ant = atual;
        atual = atual->prox;
    }
   
    if ((atual != NULL) && (atual->reg.chave==ch))
    {
        return atual;
    }
    return NULL;
}

bool inserord (Lista *l, Registro reg){
int ch = reg.chave;
Elemento* ant, *i;
i=buscaseqexc(&l, ch, &ant);
if(i!=NULL)
return false;
i=(PONT) malloc (sizeof(Elemento));
i-> reg=reg;
if(ant==NULL){
i->prox=l->inicio;
l->inicio=i;

}
else{
i->prox=ant->prox;
ant->prox=i;
}
return true;
}

bool excluir (Lista *l, int ch){
Elemento* ant, *i;
i=buscaseqexc(&l, ch, &ant);
if(i==NULL){
cout << "Item não pode ser excluído, pois ainda não pertence à lista.\n";
return false;
}
if(ant==NULL){
l->inicio=i->prox;
}
else{
ant->prox=i->prox;
}
free(i);
cout << "Item excluído com sucesso!\n";
return true;
}

int main(void){
	Lista l1;
	inicializarLista(&l1);
	Registro r;
	Elemento* poss;
	bool a;
	int y,x,b;
	while(true){
		cout<<"----BEM VINDO AO GERENCIADOR----\n\n-INSIRA 0 PARA SAIR\n-INSIRA 1 PARA INSERIR UM PRODUTO\n-INSIRA 2 PARA CONTAR A QUANTIDADE DE PRODUTOS\n";
		cout<<"-INSIRA 3 PARA PROCURAR UM PRODUTO PELA CHAVE\n-INSIRA 4 PARA MOSTRAR TODOS OS PRODUTOS EM ORDEM DE CHAVE E PRECO\n";
		cout<<"-INSIRA 5 PARA ELIMINAR UM PRODUTO\n\nescolha: ";
		cin>>x;
		switch(x){
			case 0:
				return false;
				break;
			case 1:
				cout<<"\ninsira a chave: ";
				cin>>r.chave;
				cout<<"insira o preco: ";
				cin>>r.preco;
				a=inserord(&l1,r);
				if(a==false)
				 cout<<"\n--NAO FOI POSSIVEL INSERIR O ELEMENTO--\n\n";
				else
				 cout<<"\n--ELEMENTO INSERIDO COM SUCESSO--\n\n";
				break;
			case 2:
				cout<<"\n--TAMANHO DA LISTA: "<<tamanho(&l1)<<"--\n\n";
				break;
			case 3:
				cout<<"\ninsira a chave: ";
				cin>>y;
				poss=buscaseq(&l1,y,&b);
				cout<<"\n--BUSCA CONCLUIDA--\nElemento de chave "<<y<<" achado na posicao: "<<b<<"--\n\n";
				break;
			case 4:
				exibe(&l1);
				break;
			case 5: 
			cout<<"\ninsira a chave que deseja remover: ";
			cin>>y;
			a=excluir(&l1,y);
			if(a==true)
			 cout<<"\n\n--ELEMENTO REMOVIDO COM SUCESSO--\n\n";
			else
			 cout<<"\n\n--ELEMENTO NAO REMOVIDO--\n\n";
			 break;
		}
		
		}

	return 0;
}

