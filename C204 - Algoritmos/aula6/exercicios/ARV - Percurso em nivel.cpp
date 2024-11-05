
#include <iostream>
#include <list>

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

void percursoEmNivel(node* root) {
    if (root == NULL) return;

    list<node*> fila;
    fila.push_front(root);

    while (!fila.empty()) {
        node* atual = fila.front();
        fila.pop_back();

        cout << atual->info << " ";

        if (atual->esqu != NULL) fila.push_back(atual->esqu);
        if (atual->dire != NULL) fila.push_back(atual->dire);
    }
    cout << endl;
}

int main(){
    node * root = NULL;
    int elemento;
    while (cin >> elemento, elemento != -1) {
        inserir(root, elemento);
    }

    percursoEmNivel(root);

    liberarMemoria(root);
    return 0;
}