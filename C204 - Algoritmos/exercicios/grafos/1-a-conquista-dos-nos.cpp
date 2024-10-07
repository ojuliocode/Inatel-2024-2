#include <iostream>
#include <list>

using namespace std;

int main()
{
    int nArestas, nVertices;
    cin >> nVertices >> nArestas;
    bool grafo[nVertices][nVertices];

    for (int i = 0; i < nVertices; i++)
    {

        for (int j = 0; j < nVertices; j++)
        {
            grafo[i][j] = false;
        }
    }

    int o, d;
    for(int i = 0; i < nVertices; i++){
        cin >> o >> d;
        grafo[o-1][d-1] = true; 
        grafo[d-1][o-1] = true; 
    }

    
    for (int i = 0; i < nVertices; i++)
    {

        for (int j = 0; j < nVertices; j++)
        {
            cout << grafo[i][j] << " ";

        }

        cout << endl;
    }
    return 0;
}