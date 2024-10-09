#include <iostream>
#include <list>
#define MAX 999;
using namespace std;

struct no {
    int o,d,p;
};

void prim(list<no> adj[],int cidades, int n,int s){
    bool intree[cidades];
    int parent[cidades];
    int dist[cidades];

    for(int i = 0; i < cidades; i++){
            intree[i]= false;
            parent[i] = -1;
            dist[i] = MAX;
    }
    dist[s] = 0;
    
    int v = s;

    while(intree[v] == false){
        
        intree[v] = true;
        list<no>::iterator it;
        for(it = adj[v].begin(); it != adj[v].end(); it++){
            if( it->p < dist[it->d] && intree[it->d] == false){
                dist[it->d] = it->p;
                parent[it->d] = v;

            }
        }
        v = 0;
        int minDist = MAX;
        for(int i = 0; i<cidades; i++){
            if(minDist > dist[i] && intree[i] == false){
                minDist = dist[i];
                v = i;
            }
        }
    }

    
    int total = 0;
    cout << "Arvore Geradora Minima:" << endl;
    for (int i = 0; i < cidades; i++)
    {
        if (parent[i] != -1)
            cout << parent[i] << " " << i << endl;
        total += dist[i];
    }
    cout << "Custo: " << total << endl;
    
}

int main(){
    int cidades, n;

    cin >> cidades >> n;

    list<no> adj[n];
    for(int i = 0; i < n; i++){
        int o, d, p;
        cin >> o >> d >> p;
        adj[o-1].push_back({o-1,d-1,p});
        adj[d-1].push_back({d-1,o-1,p});
    }

    prim(adj, cidades, n, 0);

    return 0;
}