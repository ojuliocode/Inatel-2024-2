#include <iostream>

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
        if(novaInformacao > atual->info){ 
            inserir(atual->esqu, novaInformacao);
        } else {
            inserir(atual->dire, novaInformacao);
        }
    }
}

void imprimirDecrescente(node * atual){
    if(atual != NULL){
        imprimirDecrescente(atual->dire);
        cout << atual->info << " ";
        imprimirDecrescente(atual->esqu);
    }
}

int main(){
    node * root = NULL;
    int elemento;
    while(cin >> elemento && elemento != -1){ 
        inserir(root, elemento);
    }

    imprimirDecrescente(root); 
    cout << endl;
    return 0;
}