#include <iostream>
#include <list>
using namespace std;

struct Aresta
{
    int origem, destino, peso;
};

void cria_aresta(list<Aresta> grafo[], int origem, int destino, int peso, int orientado)
{

    grafo[origem].push_back({origem, destino, peso});

    // Se nao for orientado, tem conexao nas duas direcoes
    if (orientado == 0)
        grafo[destino].push_back({destino, origem, peso});
}

int main()
{
    int vertices, origem, destino, orientado, peso;

    cout << "Entre com a quantidade de vertices, e com 0 ou 1 (orientado ou nao orientado)" << endl;

    // Entra com a quantidade de vertices e se eh orientado
    cin >> vertices >> orientado;

    // Cria uma lista de arrays
    list<Aresta> grafo[vertices];

    // Iterador
    list<Aresta>::iterator it;

    cin >> origem >> destino >> peso;

    // Se origem e destino e peso forem diferente de -1, continuar criando arestas
    while (!(origem == -1 && destino == -1 && peso == -1)){
        cria_aresta(grafo, origem, destino, peso, orientado);

        cout << "Entre com a origem e destino" << endl;
        cin >> origem >> destino >> peso;
    }

    for (int i = 0; i < vertices; i++)
    {
        for (it = grafo[i].begin(); it != grafo[i].end(); it++)
        {
            cout << it->origem << " " << it->destino << " " << it->peso;
            cout << endl;
        }
    }

    return 0;
}