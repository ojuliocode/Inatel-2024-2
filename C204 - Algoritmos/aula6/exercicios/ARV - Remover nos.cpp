
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

void emOrdem(node * atual){
    if(atual != NULL){
        emOrdem(atual->esqu);
        cout << atual->info << " ";
        emOrdem(atual->dire);
    }
}

int main(){
    node * root = NULL;
    int numero;
    while(cin >> numero && numero != 0){
        inserir(root, numero);
    }

    int x;
    cin >> x;

    while(deletar(root, x));

    emOrdem(root);
    cout << endl;

    return 0;
}
