#include <iostream>
#define MAX_VERTEXES 100

#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;


void dfs(int grafo[MAX_VERTEXES][MAX_VERTEXES], int origem, int vertices, bool visitados[], int pais[], int d[], int f[], int color[], int time){
    color[origem] = GREY;
    time = time + 1;
    d[origem] = time;
    visitados[origem] = true;
    for (int adj = 0; adj < vertices; adj++){
        if(grafo[origem][adj] == true && visitados[adj] == false){
            pais[adj] = origem;
            dfs(grafo, adj, vertices, visitados, pais, d, f, color, time);
        }
    }
    color[origem] = BLACK;
    f[origem] = time + 1;

    for (int i = 0; i < vertices; i++)
    {
        cout << pais[i] << " ";
    }
    cout << endl;

    
}

int main() {
    
    int vertices, origem, destino;
    cin >> vertices;

    int grafo[100][100];

    for(int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            grafo[i][j] = false;

    while(cin >> origem >> destino && origem != -1 && destino != -1){
        grafo[origem][destino] = true;
        grafo[destino][origem] = true;
    }

    bool visitado[vertices];
    int time = 0;
    for (int i = 0; i < vertices; i++)
    {
        visitado[i] = false;
    }
    int pais[vertices];
    int d[vertices];
    int f[vertices];
    int color[vertices];

    for (int i = 0; i < vertices; i++)
    {
        pais[i] = -1;
        d[i] = -1;
        f[i] = -1;
        color[i] = -1;
    }

    dfs(grafo, 0,vertices, visitado, pais, d, f , color, time);
    
    return 0;
}
