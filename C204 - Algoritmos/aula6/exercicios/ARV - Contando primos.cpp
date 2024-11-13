#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int info;
    node * esqu;
    node * dire;
};

void inserir(node *& atual, int novaInformacao){
    if(atual == NULL){
        atual = new node;
        atual->info = novaInformacao;
        atual->esqu = NULL;
        atual->dire = NULL;
    } else {
        if(novaInformacao < atual->info){
            inserir(atual->esqu, novaInformacao);
        } else {
            inserir(atual->dire, novaInformacao);
        }
    }
}

void liberarMemoria(node* atual) {
    if (atual != NULL) {
        liberarMemoria(atual->esqu);
        liberarMemoria(atual->dire);
        delete atual;
    }
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int contaPrimos(node * arvore) {
    if (arvore == NULL) return 0;
    
    int count = isPrime(arvore->info) ? 1 : 0;
    count += contaPrimos(arvore->esqu);
    count += contaPrimos(arvore->dire);
    
    return count;
}

int main() {
    node * root = NULL;
    int elemento;

    while (true) {
        cin >> elemento;
        if (elemento == -1) break;
        inserir(root, elemento);
    }

    int primeCount = contaPrimos(root);
    cout << primeCount << " numeros primos" << endl;

    liberarMemoria(root);
    return 0;
}