#include <iostream>
#include <string>

using namespace std;

int buscarElemento(string ilhas[], int indiceMaisBaixo, int indiceMaisAlto, string elementoBuscado) {
    if (indiceMaisAlto >= indiceMaisBaixo) {
        int indiceDoMeio = indiceMaisBaixo + (indiceMaisAlto - indiceMaisBaixo) / 2;

        if (ilhas[indiceDoMeio] == elementoBuscado)
            return indiceDoMeio;

        if (ilhas[indiceDoMeio] > elementoBuscado)
            return buscarElemento(ilhas, indiceMaisBaixo, indiceDoMeio - 1, elementoBuscado);

        return buscarElemento(ilhas, indiceDoMeio + 1, indiceMaisAlto, elementoBuscado);
    }

    return -1;
}

int main() {
    string ilhas[7];
    string elementoBuscado;

    for (int i = 0; i < 7; i++) {
        getline(cin, ilhas[i]);
    }

    cin >> elementoBuscado;

    int n = sizeof(ilhas) / sizeof(ilhas[0]);
    int resultado = buscarElemento(ilhas, 0, n - 1, elementoBuscado);
    if (resultado == -1)
        cout << -1;
    else
        cout << "Índice da pista encontrada: " << resultado;
    return 0;
}