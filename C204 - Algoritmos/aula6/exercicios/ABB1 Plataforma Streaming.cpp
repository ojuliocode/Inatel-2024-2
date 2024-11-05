#include <iostream>
#include <string>

using namespace std;
struct filme
{
    string nome, genero;
    int duracao, ano, classificacao;
};

struct node
{
    filme info;
    node *esqu;
    node *dire;
};

void inserir(node *&atual, filme novaInformacao)
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

int main()
{
    node *root = NULL;
    int elemento;
    int opcao = -1;
    filme *newFilme = new filme;
    while (opcao != 0)
    {
        cin >> opcao;
        if (opcao == 1)
        {
            cin.ignore();
            getline(cin, newFilme->nome);
            getline(cin, newFilme->genero);
            cin >> newFilme->duracao;
            cin >> newFilme->classificacao;
            cin >> newFilme->ano;

            inserir(root, *newFilme);
        }
        else if (opcao == 2)
        {
            string nome;
            cin.ignore();
            getline(cin,  nome);
            node *resultado = pesquisar(root, nome);
            if (resultado != NULL)
            {
                cout << "Nome: " << resultado->info.nome << endl;
                cout << "Genero: " << resultado->info.genero << endl;
                cout << "Duracao: " << resultado->info.duracao << " mins" << endl;
                cout << "Classificacao: " << resultado->info.classificacao << endl;
                cout << "Ano: " << resultado->info.ano << endl;
            }
            else
            {
                cout << "Filme nao encontrado" << endl;
            }
        }
        else
        {
            if(opcao != 0)
                cout << "Operacao invalida" << endl;
        }
    }

    return 0;
}