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
	
	cout<<"Menor caminho: ";
	list<int> apresentacao;
	int aux = end;
	do{
		apresentacao.push_front(aux);
		aux = parent[aux];
	}while(aux != start);
	cout << start << " ";
	while(!apresentacao.empty()){
		cout << apresentacao.front() << " ";
		apresentacao.pop_front();
	}
	cout<<"\nCusto: "<<distance[end];
	
	return distance[end];
		
}            

int main(){
	int vertices, arestas, origem, destino, peso, orientado, vInicial, vFinal;
	cin >> vertices >> orientado >>  vInicial >> vFinal;
	
	list<Aresta> grafo[vertices];
	list<Aresta>::iterator it;
	
	cin >> origem >> destino >> peso;

    while(!(origem == -1 && destino == -1 && peso == -1)){
		grafo[origem].push_back({origem, destino, peso});
        if(orientado == 0)
		    grafo[destino].push_back({destino, origem, peso});
		cin >> origem >> destino >> peso;
    }
    
	
	dijkstra(grafo, vertices, vInicial, vFinal);
    
	return 0;
}