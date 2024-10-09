#include <iostream>
#include <list>

using namespace std;

struct aresta {
    int o,d;
};

void bfs(list<aresta>adj[], int n, int s){
    bool intree[n];
    int parent[n];
    list<int> filaVisitacao;

    for(int i = 0; i<n; i++){
        if(i != s){
            intree[i] = false;
            parent[i] = -1;
        }
    }

    intree[s] = true;
    parent[s] = -1;
    filaVisitacao.push_back(s);
    int v = s;
    while(!filaVisitacao.empty()){
        filaVisitacao.pop_front();
        list<aresta>::iterator it;
        for(it = adj[v].begin(); it!=adj[v].end(); it++){
            if(intree[it->d] == false){
                intree[it->d] = true;
                filaVisitacao.push_back(it->d);
            }
        }
        v = filaVisitacao.front();
    }
    bool c = true;
    for(int i = 0; i<n; i++){
        if(intree[i] == false)
            c = false;
        
    }

    if(c)
        cout << "Conexo";
    else 
        cout << "Desconexo";
}


int main(){
    int n, s;
    cin >> n >> s;

    list<aresta> adj[n];

    int o,d;

    cin >> o >> d;

    while(!(o == -1 && d == -1)){
        adj[o].push_back({o,d});
        adj[d].push_back({d,o});
        cin >> o >> d;
    };

    bfs(adj, n, s);
    return 0;
}