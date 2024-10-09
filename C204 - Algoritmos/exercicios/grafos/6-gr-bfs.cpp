#include <iostream>
#include <list>

using namespace std;

struct no {
    int o, d, p;
};
void bfs(list<no>adj[], int n, int s){
    list<int> filaVisitacao;
    bool intree[n];
    int parent[n];
    for(int i = 0; i < n; i++){
        if(i != s){
            intree[i] = false;
            parent[i] = -1;
        }
    }
    filaVisitacao.push_back(s);
    intree[s] = true;
    parent[s] = -1;

    while(!filaVisitacao.empty()){
        int u = *filaVisitacao.begin();
        filaVisitacao.pop_front();
        cout << u << endl;
        list<no>::iterator it;
        for(it = adj[u].begin(); it != adj[u].end(); it++){
            int v = it->d;
            cout << u << " " << v << endl;
            if(intree[v] == false){
                intree[v] = true;
                parent[v] = u;
                filaVisitacao.push_back(v);
            }
        }

        intree[u] = true;
    }
}

int main(){
    int nvertices, s;
    cin >> nvertices >> s;
    list<no>::iterator it;
    list<no> adj[nvertices];
    int o,d,p;
    cin>>o>>d>>p;
    while(!(o==-1 && d==-1 && p==-1)){
        adj[o].push_back({o,d,p});
        adj[d].push_back({d,o,p});
        cin>>o>>d>>p;
    }

    bfs(adj, nvertices, s);
    
    return 0;
}