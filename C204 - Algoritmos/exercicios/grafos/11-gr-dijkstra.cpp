#include <iostream>
#include <list>

#define MAX_INT 999;

using namespace std;

struct Aresta{
    int origem, destino, peso;
};

void dijkstra(list<Aresta> adj[], int numeroDeVertices, int verticeInicial, int verticeDestino){
    bool intree[numeroDeVertices];
    int parent[numeroDeVertices];
    int distance[numeroDeVertices];

    for (int i = 0; i < numeroDeVertices; i++){
        intree[i] = false;
        parent[i] = -1;
        distance[i] = MAX_INT;
    } 

    distance[verticeInicial] = 0;

    int verticeAtual = verticeInicial;

    while(intree[verticeAtual] == false){
        intree[verticeAtual] = true;
        list<Aresta>::iterator it;
        for(it = adj[verticeAtual].begin(); it != adj[verticeAtual].end(); it++){

            Aresta aresta = *it;

            if(distance[verticeAtual] + aresta.peso < distance[aresta.destino]){
                distance[aresta.destino] = distance[verticeAtual] + aresta.peso;
                parent[aresta.destino] = verticeAtual;

            }
        }

        verticeAtual = 0;
        int dist = MAX_INT;
        for(int i = 0; i < numeroDeVertices; i++){
            if(dist > distance[i] && intree[i] == false){
                dist = distance[i];
                verticeAtual = i;
            }
        }
    }
    
    cout<<"Caminho Minimimo:"<<endl;
	list<int> apresentacao;
	int aux = verticeDestino;
	do{
		apresentacao.push_front(aux);
		aux = parent[aux];
	}while(aux != start);
        cout << "Custo: " << distance[verticeDestino];
}

int main(){
    int numeroDeVertices, ehOrientado, verticeInicial, verticeDestino, origem, destino, peso;

    cin >> numeroDeVertices >> ehOrientado >> verticeInicial >> verticeDestino;

    list<Aresta> adjacencia[numeroDeVertices];
    list<Aresta>::iterator it;

    cin >> origem >> destino >> peso;

    while(!(origem == -1 && destino == -1 && peso == -1)){
        adjacencia[origem].push_back({ origem, destino, peso });
        if(ehOrientado == 0){
            adjacencia[destino].push_back({ destino, origem, peso});
        }
        cin >> origem >> destino >> peso;
    }

dijkstra(adjacencia, numeroDeVertices, verticeInicial, verticeDestino);

    return 0;
}