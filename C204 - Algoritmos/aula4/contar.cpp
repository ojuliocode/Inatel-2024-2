#include <iostream>
#include <list>
using namespace std;

int contar(list<int> lista) {
    int contagem=0;
    for (int item : lista) {
        contagem++;
    }
    return contagem;
}

int main() {
    int item = -1;
    list<int> lista;
        cin >> item;
    while(item != 0) {
        lista.push_back(item);
        cin >> item;
    }

    cout << contar(lista);
    return 0;
}
