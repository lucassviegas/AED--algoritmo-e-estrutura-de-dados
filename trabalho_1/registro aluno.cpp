#include <iostream>
#include <cmath>
#define TAM 3

using namespace std;
struct ficha {
    int matricula;
    float nota;
};

int main()
{
    ficha fichaaluno[TAM];
    int i;
    for (i = 0; i < TAM;i++)
    {
        cout << "digite a matricula do aluno" << i + 1 << "o aluno: ";
        cin >> fichaaluno[i].matricula;
        cout << "digite a nota do " << i + 1 << " o aluno";
        cin >> fichaaluno[i].nota;
    }
    for (i = 0; i < TAM;i++)
    {
        cout << "o aluno " << fichaaluno[i].matricula << "tirou nota" << fichaaluno[i].nota << endl;
    }
        return 0;
}

