
#include <iostream>
#include <iomanip>

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

int somarElementos(node * atual) {
    if(atual == NULL) return 0;
    return atual->info + somarElementos(atual->esqu) + somarElementos(atual->dire);
}

int contarElementos(node * atual) {
    if(atual == NULL) return 0;
    // recursividade simples pra contar os elementos da esquerda e da direita
    return 1 + contarElementos(atual->esqu) + contarElementos(atual->dire);
}

float media(node * arvore) {
    int soma = somarElementos(arvore);
    int contagem = contarElementos(arvore);
    // aqui to usando ternario ao inves de if else
    return contagem == 0 ? 0 : (float)(soma) / contagem;
}

int main(){
    node * root = NULL;
    int elemento;
    while(cin >> elemento && elemento != -1){
        inserir(root, elemento);
    }

    float resultadoMedia = media(root);
    cout << fixed << setprecision(2) << resultadoMedia << endl;
    return 0;
}
