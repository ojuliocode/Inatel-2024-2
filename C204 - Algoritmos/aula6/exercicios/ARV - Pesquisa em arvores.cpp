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

node * pesquisar (node * atual, int pesquisado){
    if(atual == NULL)
        return NULL;
    if(pesquisado == atual->info)
        return atual;
    if(pesquisado < atual->info)
        return pesquisar(atual->esqu, pesquisado);
    return pesquisar(atual->dire, pesquisado);

}

int main(){
    node * root = NULL;
    int qtElementos;
    cin >> qtElementos;
    int elemento;
    for(int i = 0; i < qtElementos; i++){
        cin >> elemento;
        inserir(root, elemento);
    }

    int pesquisado;
    cin >> pesquisado;
    node * resultado = pesquisar(root, pesquisado);
    if(resultado != NULL)
        cout << "Encontrado" << endl;
    else 
        cout << "Nao encontrado" << endl;
    return 0;
}