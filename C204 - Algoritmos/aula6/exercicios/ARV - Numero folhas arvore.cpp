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

int contaFolhas(node * arvore) {
    if (arvore == NULL) return 0;
    
    if (arvore->esqu == NULL && arvore->dire == NULL) {
        return 1;
    }

    return contaFolhas(arvore->esqu) + contaFolhas(arvore->dire);
}

int main() {
    node * root = NULL;
    int elemento;

    while (true) {
        cin >> elemento;
        if (elemento == -1) break;
        inserir(root, elemento);
    }

    int leafCount = contaFolhas(root);
    cout << leafCount << endl;

    liberarMemoria(root);
    return 0;
}