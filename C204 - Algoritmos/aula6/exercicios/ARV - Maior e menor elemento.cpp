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
        if(novaInformacao < atual->info){
            inserir(atual->esqu, novaInformacao);
        } else {
            inserir(atual->dire, novaInformacao);
        }
    }
}

int maior(node * atual){
    if(atual->dire != NULL){
        return maior(atual->dire);
    }else{
        return atual->info;
    }
}

int menor(node * atual){
    if(atual->esqu != NULL){
        return menor(atual->esqu);
    }else{
        return atual->info;
    }
}

int main(){
    node * root = NULL;
    int numero;
    while(cin >> numero && numero != -1){
        inserir(root, numero);
    }

    if(root != NULL){
        cout << menor(root) << " e " << maior(root);
    }

    return 0;
}