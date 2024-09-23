#include <iostream>
#include <list>
using namespace std;

struct Aresta
{
    int origem, destino, peso;
};

bool bfs(list<Aresta> grafo[], int vertices, int origem)
{
    bool visitado[vertices];
    
    list<int> fila_visitacao;

    list<Aresta>::iterator it;

    for (int i = 0; i < vertices; i++)
        visitado[i] = false;

    fila_visitacao.push_back(origem);

    visitado[origem] = true;

    while (!fila_visitacao.empty())
    {

        int atual = fila_visitacao.front();

        for (it = grafo[atual].begin(); it != grafo[atual].end(); it++)
        {

            int i = it->destino;

            if (!visitado[i])
            {

                if (it->peso != 0)
                {
                    fila_visitacao.push_back(i);
                    visitado[i] = true;
                }
            }
        }

        // Tira o da frente da visitacao (acabou de ser visitado)
        fila_visitacao.pop_front();
    }

    list<int>::iterator itera;

    for (int i = 1; i <= vertices; i++)
    {
        if (!visitado[i])
            cout << i << " ";
    }

    return true;
}

void cria_aresta(list<Aresta> grafo[], int origem, int destino)
{

    grafo[origem].push_back({origem, destino, 1});
    grafo[destino].push_back({destino, origem, 1});
}

int main()
{
    int vertices, origem, destino, arestas, peso;

    cin >> vertices >> arestas;

    list<Aresta> grafo[vertices + 1];

    list<Aresta>::iterator it;

    for (int i = 0; i < arestas; i++)
    {
        cin >> origem >> destino;
        cria_aresta(grafo, origem, destino);
    }

    int ponteQuebradaOrigem, ponteQuebradaDestino;
    cin >> ponteQuebradaOrigem >> ponteQuebradaDestino;
    for (int i = 1; i <= vertices; i++)
    {
        for (it = grafo[i].begin(); it != grafo[i].end(); it++)
        {
            if (it->origem == ponteQuebradaOrigem && it->destino == ponteQuebradaDestino)
                it->peso = 0;
            if (it->destino == ponteQuebradaOrigem && it->origem == ponteQuebradaDestino)
                it->peso = 0;
        }
    }

    bfs(grafo, vertices, 1);
    return 0;
}