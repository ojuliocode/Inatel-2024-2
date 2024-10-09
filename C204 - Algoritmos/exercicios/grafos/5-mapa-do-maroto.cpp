#include <iostream>
#include <list>

using namespace std;

struct Aresta{
    int orig, dest, peso;
};
int main(){
    int vertices, orientado;

    cin >> vertices >> orientado;


    list<Aresta> caminhos[vertices];
    list<Aresta>::iterator it;
    int o,d,p;

    cin >> o >> d >> p;

    while (!(o == -1 && d == -1 && p == -1)){
        caminhos[o].push_back({ o, d, p});
        if(orientado == 0)
            caminhos[d].push_back({d,o,p});
        cin >> o >> d >> p;
    } 

    for(int i = 0; i < vertices; i++){
        for(it = caminhos[i].begin(); it != caminhos[i].end(); it++){
            cout << it->orig;
            cout << " ";
            cout << it->dest; 
            cout << " ";
            cout << it->peso;
            cout << endl;
        }
    }
    return 0;
}