#include <iostream>
#include <list>
using namespace std;

struct Aresta
{
    int origem, destino;
};

void cria_aresta(list<Aresta> grafo[], int origem, int destino)
{
    // cout << "Criada adjacencia entre: " << origem << " e " << destino << endl;
    grafo[origem].push_back({origem, destino});
    grafo[destino].push_back({destino, origem});
}

int main()
{
    int vertices, arestas, origem, destino;

    cin >> vertices >> arestas;

    // Tive que criar grafo com arestas + 1 pois ele comeca em 1 ate 4 (e nao de 0 a te 3)
    list<Aresta> grafo[arestas + 1];

    list<Aresta>::iterator it;

    for (int i = 1; i <= vertices; i++)
    {
        cin >> origem >> destino;
        cria_aresta(grafo, origem, destino);
    }
    
    

    for (int i = 1; i <= vertices; i++)
    {
        // cout << i << " >> ";
        cout << grafo[i].size() << " ";
        for (it = grafo[i].begin(); it != grafo[i].end(); it++)
        {
            cout << it->destino << " ";
        }
        cout << endl;
    }

    return 0;
}