#include <iostream>
#include <list>
using namespace std;

int soma(list<int> lista) {
    int soma=0;
    for (int item : lista) {
        soma+=item;
    }
    return soma;
}

int main() {
    int item = -1;
    list<int> lista;
    while(item != 0) {
        cin >> item;
        lista.push_back(item);
    }

    cout << soma(lista);
    return 0;
}
