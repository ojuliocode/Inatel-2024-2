#include <iostream>
#include <string>
#include <list>

using namespace std;

struct caminho {
    int origem, destino;
};
int main(){
    int nCidades, nCaminhos, origem, destino, distancia;

    cin >> nCidades >> nCaminhos;

    list<caminho> adjacencia[nCaminhos];
    list<caminho>::iterator it;

    for(int i = 0; i < nCaminhos; i++){
        cin >> origem >> destino;
        adjacencia[origem-1].push_back({ origem-1, destino-1 });
        adjacencia[destino-1].push_back({ destino-1, origem-1 });   

    }

    for(int i = 0; i < nCaminhos; i++){
        cout << adjacencia[i].size() << " ";
        for(it = adjacencia[i].begin(); it != adjacencia[i].end(); it++){
            cout  << it->destino + 1<< " ";
        }
        cout << endl;
    }


    return 0;
}