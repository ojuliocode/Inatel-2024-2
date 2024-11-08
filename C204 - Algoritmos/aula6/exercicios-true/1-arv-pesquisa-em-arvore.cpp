#include <iostream>

using namespace std;

struct node {
    int info;
    node * left;
    node * right;
};

void insert(node *& curr, int new_info){
    if(curr == NULL){
        curr = new node;
        curr->info = new_info;
        curr->left = NULL;
        curr->right = NULL;
    } else {
        if(new_info < curr->info){
            insert(curr->left, new_info);
        } else {
            insert(curr->right, new_info);
        }
    }
}

node * search (node * curr, int searchedTerm){
    if(curr == NULL)
        return NULL;
    if(searchedTerm == curr->info)
        return curr;
    if(searchedTerm < curr->info)
        return search(curr->left, searchedTerm);
    return search(curr->right, searchedTerm);

}

int main(){
    // Ponteiro para o no root
    node * root = NULL;

    // Quantidade de itens
    int quantidadeDeItens;

    cin >> quantidadeDeItens;

    for(int i = 0; i < quantidadeDeItens; i++){
        int item;
        cin >> item;
        insert(root, item);
    }

    int paraSerProcurado;
    cin >> paraSerProcurado;

    node * result = search(root, paraSerProcurado);
    if(result != NULL)
        cout << "Econtrado" << endl;
    else 
        cout << "Nao encontrado" << endl;
    return 0;
}