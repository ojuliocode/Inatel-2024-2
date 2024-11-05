#include <iostream>
#include <string>
#define INSERIR 1
#define PESQUISAR 2
#define REMOVER 3
#define TERMINAR 0

using namespace std;

struct Rocha
{
    string nome, tipo;
};

struct node
{
    Rocha info;
    node *esqu;
    node *dire;
};

void inserir(node *&atual, Rocha novaInformacao)
{
    if (atual == NULL)
    {
        atual = new node;
        atual->info = novaInformacao;
        atual->esqu = NULL;
        atual->dire = NULL;
    }
    else
    {
        if (novaInformacao.nome < atual->info.nome)
        {
            inserir(atual->esqu, novaInformacao);
        }
        else
        {
            inserir(atual->dire, novaInformacao);
        }
    }
}

node *pesquisar(node *atual, string pesquisado)
{
    if (atual == NULL)
        return NULL;
    if (pesquisado == atual->info.nome)
        return atual;
    if (pesquisado < atual->info.nome)
        return pesquisar(atual->esqu, pesquisado);
    return pesquisar(atual->dire, pesquisado);
}

node *acharMenor(node *&p)
{
    node *t = p;
    if (p->esqu == NULL)
    {
        p = p->dire;
        return t;
    }
    else
    {
        return acharMenor(p->esqu);
    }
}

bool deletar(node *&p, string x, string tipo)
{
    node *t;
    if (p == NULL)
        return false;
    if (x == p->info.nome && p->info.tipo == tipo)
    {
        t = p;
        if (p->esqu == NULL)
            p = p->dire;
        else if (p->dire == NULL)
            p = p->esqu;
        else
        {
            t = acharMenor(p->dire);
            p->info = t->info;
        }
        
            delete t;
            return true;
    }
    else if (x < p->info.nome)
        return deletar(p->esqu, x, tipo);
    else
        return deletar(p->dire, x, tipo);
}

int main()
{
    node *root = NULL;
    int opcao = -1;
    while (opcao != TERMINAR)
    {
        cin >> opcao;
        if (opcao == INSERIR)
        {
            string nome, tipo;
            cin.ignore();
            getline(cin, nome);
            getline(cin, tipo);
            Rocha rocha = {nome, tipo};
            inserir(root, rocha);
        }
        else if (opcao == PESQUISAR)
        {
            string pesquisado;
            cin.ignore();
            getline(cin, pesquisado);
            node *searched = pesquisar(root, pesquisado);
            if (searched != NULL)
            {
                cout << "Nome: " << searched->info.nome << endl;
                cout << "Tipo: " << searched->info.tipo << endl;
            }
            else
            {
                cout << "Rocha nao encontrada" << endl;
            }
        }
        else if (opcao == REMOVER)
        {
            string nome, tipo;
            cin.ignore();
            getline(cin, nome);
            getline(cin, tipo);
            bool del = deletar(root, nome, tipo);
            if (del == true)
                cout << "Rocha removida com sucesso";
            else
                cout << "Rocha nao encontrada para remocao";
            cout << endl;
        }
    }

    return 0;
}