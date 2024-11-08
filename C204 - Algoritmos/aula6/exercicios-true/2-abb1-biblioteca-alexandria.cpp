#include <iostream>

using namespace std;

struct node {
    node * esq;
    node * dir;
    int info;
};


void inserir(node *& noAtual, int info){
    if(noAtual == NULL){
        noAtual = new node;
        noAtual->dir = NULL;
        noAtual->esq = NULL;
        noAtual->info = info;
    } else {
        if(info >= noAtual->info)
            inserir(noAtual->dir, info);
        else
            inserir(noAtual->esq, info);
    }
}

bool procurar(node *& noAtual, int itemProcurado){
    if(noAtual == NULL)
        return false;
    
    if(noAtual->info == itemProcurado)
        return true;
    
    if(itemProcurado > noAtual->info)
        return procurar(noAtual->dir, itemProcurado);
    
    if(itemProcurado < noAtual->info)
        return procurar(noAtual->esq, itemProcurado);

}


int main(){
    // No raiz
    node * raiz = NULL;

    int qtItens;
    cin >> qtItens;

    for(int i=0;i<qtItens;i++){
        int item;
        char opcao;

        cin >> opcao;
        cin >> item;
        if(opcao == 'i')
            inserir(raiz, item);
        else 
            if(procurar(raiz, item))
                cout << "Sim" << endl;
            else 
                cout << "Nao" << endl;
    }

    return 0;
}