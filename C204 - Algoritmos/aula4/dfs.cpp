#include <iostream>
#define MAX_VERTEXES 100
using namespace std;

void dfs(bool grafo[MAX_VERTEXES][MAX_VERTEXES], int origem, int vertices, bool visitados[]){
    visitados[origem] = true;
    for (int adj = 0; adj < vertices; adj++){
        if(grafo[origem][adj] == true && visitados[adj] == false){
            dfs(grafo, adj, vertices, visitados);
        }
    }
    
    
}

int main() {
    
    int vertices, origem, destino;
    cin >> vertices;

    bool grafo[vertices][vertices];

    for(int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            grafo[i][j] = false;

    while(cin >> origem >> destino && origem != -1 && destino != -1){
        grafo[origem][destino] = true;
        grafo[destino][origem] = true;
    }

    bool visitado[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visitado[i] = false;
    }
    
    dfs(grafo, 0,vertices, visitado);
    
    return 0;
}
