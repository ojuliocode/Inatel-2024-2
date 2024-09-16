#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<int> lista, int x) {

    for (int test1 : lista) {
        if(test1 == x)
            return true;
    }
    return false;

}
int main() {
    list<int> test;

    int t = -1;
    while (t != 0) {
        cin >> t;
        test.push_back(t);
    }

    int procurar;
    cin >> procurar;

    bool encontrou = encontrar(test, procurar);

    if(encontrou)
        cout << "Encontrado";
    else
        cout << "Nao encontrado";

    return 0;
}
