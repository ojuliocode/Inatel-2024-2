#include<iostream>
#include<string>
#include<list>
using namespace std;

#define INT_MAX 99999

struct Estrada{
	int orig;
	int dest;
	int distancia;
};

struct Cidade {
	string nome;
	int codigo;
	float idh;
	list<Estrada> vizinhos;
};

int shortest_path_dijkstra(list<Estrada>adj[], int vertices, int start, int end, float idh){
	bool intree[vertices];
	int distance[vertices], parent[vertices];
	
	for(int u = 0; u < vertices; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
	}
    distance[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
		list<Estrada>::iterator p;
    	for(p = adj[v].begin(); p != adj[v].end(); p++){
            int dest = p->dest;
            int weight = p->distancia;
            if(distance[dest] > distance[v]+weight){
                distance[dest] = distance[v]+weight;
                parent[dest] = v;
			}
		}
        v = 0;
        int dist = INT_MAX;
        for(int u = 0; u < vertices; u++){
            if(intree[u]==false && dist>distance[u]){
                dist = distance[u];
                v = u;
			}
		}
	}
	return distance[end];
}



int main(){
	
	int num_cidades;
    
	cin >> num_cidades;
	
	Cidade cidades[num_cidades];
	
	for(int i=0; i< num_cidades; i++){
		cidades[i].codigo = i;
    
		cin >> cidades[i].nome;
    
		cin >> cidades[i].idh;
	}
	
	int num_estradas, origem, destino, distancia;
	
    
    cin >> num_estradas;
	
	for(int j=0; j < num_estradas; j++){
    
		cin >> origem;
    
		cin >> destino;
    
		cin >> distancia;
		cidades[origem].vizinhos.push_back({origem, destino, distancia});
	}
	
	float idh;
	
    
	cin>>origem>>destino>>idh;
	
    list<Estrada> caminhosValidadosPorIdh[num_estradas];
	list<Estrada>::iterator it;

    for(int i = 0; i < num_cidades; i++){
        for(it = cidades[i].vizinhos.begin();it != cidades[i].vizinhos.end(); it++){
            if(cidades[it->orig].idh >= idh && cidades[it->dest].idh >= idh){
                
                caminhosValidadosPorIdh[it->orig].push_back({ 
                    it->orig, it->dest, it->distancia
                });
                caminhosValidadosPorIdh[it->dest].push_back({ 
                    it->dest, it->orig, it->distancia
                });
            }
        }
    }
    
	cout << shortest_path_dijkstra(caminhosValidadosPorIdh, num_cidades,origem, destino, idh) << endl;
	
	
}