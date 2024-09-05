//
// Created by julio on 9/5/2024.
//

#include <iostream>

using namespace std;

int buscaSequencial(int tamanho, int *vetor, int elemento) {
    for(int i = 0; i < tamanho; i++) {
        if(vetor[i] == elemento)
            return i;
    }
    return -1;
}


int main() {
    int tamanho;

    cin >> tamanho;

    int vetor[tamanho];

    for(int i = 0; i < tamanho; i++) {
        cin >> vetor[i];
    }

    int elemento;

    cin >> elemento;

    int index = buscaSequencial(tamanho, vetor,elemento);

    if(index != -1)
        cout << "Achou na posicao " << index << endl;
    else
        cout << "Nao encontrado";
    return 0;
}