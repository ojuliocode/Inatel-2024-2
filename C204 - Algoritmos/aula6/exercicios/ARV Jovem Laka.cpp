#include <iostream>
#include <list>
#include <string>

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

int preordem(node* root, int cidadeX) {
    if (root == NULL) return 0;
    if (root->info == cidadeX) return 1;
    return 1 + preordem(root->esqu, cidadeX) + preordem(root->dire, cidadeX);
}

int emordem(node* root, int cidadeX) {
    if (root == NULL) return 0;
    int esq = emordem(root->esqu, cidadeX);
    if (esq > 0) return esq + 1;
    if (root->info == cidadeX) return 1;
    return 1 + emordem(root->dire, cidadeX);
}

int posordem(node* root, int cidadeX) {
    if (root == NULL) return 0;
    int esq = posordem(root->esqu, cidadeX);
    if (esq > 0) return esq + 1;
    int dir = posordem(root->dire, cidadeX);
    if (dir > 0) return dir + 1;
    if (root->info == cidadeX) return 1;
    return 1 + esq + dir;
}

int main() {
    node * root = NULL;
    int elemento;
    string caminho;

    while (cin >> elemento && elemento != -1) {
        inserir(root, elemento);
    }

    int cidadeX;
    cin >> cidadeX;

    int preordemCount = preordem(root, cidadeX);
    int emordemCount = emordem(root, cidadeX);
    int posordemCount = posordem(root, cidadeX);

    string shortestPath = "";

    if (preordemCount < emordemCount && preordemCount < posordemCount) {
        shortestPath = "Pre";
    } else if (emordemCount < preordemCount && emordemCount < posordemCount) {
        shortestPath = "Em";
    } else {
        shortestPath = "Pos";
    }

    cout << shortestPath << endl;

    liberarMemoria(root);
    return 0;
}