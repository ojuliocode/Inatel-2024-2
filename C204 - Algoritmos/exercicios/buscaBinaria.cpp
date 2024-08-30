#include <iostream>
#include <vector>

using namespace std;

int busca_binaria(int arr[], int indiceMaisAbaixo, int indiceDaDireita, int valor_procurado) {
    if (indiceMaisAbaixo > indiceDaDireita) {
        return -1;
        // early return pra condicao de parada
    }

    int indicaCentral = indiceMaisAbaixo + (indiceDaDireita - indiceMaisAbaixo) / 2;

    if (arr[indicaCentral] == valor_procurado) {
        return indicaCentral; 
    // aqui a gente ta fazendo a chamada recursiva pra ir OU pra metade de cima OU pra metade de baixo
    } else if (arr[indicaCentral] > valor_procurado) {
        return busca_binaria(arr, indiceMaisAbaixo, indicaCentral - 1, valor_procurado); 
    } else {
        return busca_binaria(arr, indicaCentral + 1, indiceDaDireita, valor_procurado); 
    }
}

int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int valor_procurado;
    cin >> valor_procurado;

    int result = busca_binaria(arr, 0, N - 1, valor_procurado);

    cout << result << endl;

    return 0;
}
