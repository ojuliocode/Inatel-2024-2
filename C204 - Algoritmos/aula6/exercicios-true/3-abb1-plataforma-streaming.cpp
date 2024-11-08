#include <iostream>

using namespace std;

struct Filme
{
    string nome, genero;
    int duracao, classificacao, ano;
};

struct node
{
    node *esq;
    node *dir;
    Filme info;
};

void inserir(node *&noAtual, Filme info)
{
    if (noAtual == NULL)
    {
        noAtual = new node;
        noAtual->dir = NULL;
        noAtual->esq = NULL;
        noAtual->info = info;
    }
    else
    {
        if (info.nome >= noAtual->info.nome)
            inserir(noAtual->dir, info);
        else
            inserir(noAtual->esq, info);
    }
}

Filme *procurar(node *&noAtual, string itemProcurado)
{
    if (noAtual == NULL)
        return NULL;

    if (noAtual->info.nome == itemProcurado)
        return &(noAtual->info);

    if (itemProcurado > noAtual->info.nome)
        return procurar(noAtual->dir, itemProcurado);

    if (itemProcurado < noAtual->info.nome)
        return procurar(noAtual->esq, itemProcurado);
}

int main()
{
    // No raiz
    node *raiz = NULL;

    int input = -1;

    while (input != 0)
    {
        Filme *achou = NULL;
        string nome, genero, procurado;
        int duracao, classificacao, ano;
        cin >> input;
        switch (input)
        {
        case 1:
            cin.ignore();
            getline(cin, nome);
            getline(cin, genero);
            
            cin >> duracao >> classificacao >> ano;
            inserir(raiz, {nome, genero, duracao, classificacao, ano});
            break;
        case 2:
            cin.ignore();
            getline(cin, procurado);
            achou = procurar(raiz, procurado);
            if (achou != NULL)
            {
                cout << "Nome:" << achou->nome << endl;
                cout << "Genero:" << achou->genero << endl;
                cout << "Duracao:" << achou->duracao << endl;
                cout << "Classificacao:" << achou->classificacao << endl;
                cout << "Ano:" << achou->ano << endl;
            }
            else
            {
                cout << "Filme nao encontrado" << endl;
            }
            break;
        default:
            if(input != 0)
                cout << "Operacao invalida" << endl;
            break;
        }
    }

    return 0;
}