#include <iostream>

#define INSERIR 1
#define PESQUISAR 2
#define REMOVER 3
#define TERMINAR 0

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

node * acharMenor(node *& p){
    node * t = p;
    if(p->esqu == NULL){
        p = p->dire;
        return t;
    } else {
        return acharMenor(p->esqu);
    }
}

bool deletar(node *& p, int x){
    node * t;
    if(p == NULL) return false;
    if(x == p->info){
        t = p;
        if(p->esqu == NULL)
            p = p->dire;
        else if(p->dire == NULL)
            p = p->esqu;
        else {
            t = acharMenor(p->dire);
            p->info = t->info;
        }
        delete t;
        return true;
    } else if (x < p->info) return deletar(p->esqu, x);
    else return deletar(p->dire, x);
}


int main(){
    node * root = NULL;
    int qtElementos;
    cin >> qtElementos;
    int elemento;
    char opcao;
    for(int i = 0; i < qtElementos; i++){
        cin.ignore();
        cin >> opcao;
        cin >> elemento;
        if(opcao == 'i')
            inserir(root, elemento);
        else if(opcao == 'b') {
            node * resultado = pesquisar(root, elemento);
            if(resultado != NULL)
                cout << "Sim" << endl;
            else 
                cout << "Não" << endl;
        } else {
            deletar(root, elemento);
        }

    }

    return 0;
}