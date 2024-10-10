#include<iostream>
#include<list>

#define MAX_VERTICES 10
#define INT_MAX 999999

using namespace std;

struct Aresta {
	int origem, destino, peso;
};


int dijkstra(list<Aresta> adj[], int n, int start, int end){
    bool intree[n];
    int distance[n], parent[n];
	for(int i=0; i<n; i++){
		intree[i] = false;
		distance[i] = INT_MAX;
		parent[i] = -1;
	}
    distance[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
        list<Aresta>::iterator it;
        for(it = adj[v].begin();it != adj[v].end(); it++){
			Aresta aresta = *it;
            if(distance[v] + aresta.peso < distance[aresta.destino]){
                distance[aresta.destino] = distance[v] + aresta.peso;
                parent[aresta.destino] = v;
			}
		}
        v = 0;
        int dist = INT_MAX;
        for(int i=0; i<n; i++){
            if(intree[i]==false && dist>distance[i]){
                dist = distance[i];
                v = i;
			}
		}
	}

    // somar mais pq ele quer o numero de salas, nao o numero de saltos
    if(distance[end])
	    cout<<distance[end] + 1<<endl;
    else 
        cout << "IMPOSSIVEL";
	
	return distance[end];
		
}            

int main(){
	int vertices, arestas, origem, destino, dijOrigem, dijDestino;
	cin >> vertices >> arestas;
	
	//int grafo[vertices][vertices];
	list<Aresta> grafo[vertices + 1];
	list<Aresta>::iterator it;
	
		
    for(int i=0; i< arestas; i++){
		cin >> origem >> destino;
		// grafo[origem][destino] = peso;
		// grafo[destino][origem] = peso;
		grafo[origem].push_back({origem, destino, 1});
		grafo[destino].push_back({destino, origem, 1});
    }
	
    cin >> dijOrigem >> dijDestino;
	dijkstra(grafo, vertices, dijOrigem, dijDestino);
    
	return 0;
}