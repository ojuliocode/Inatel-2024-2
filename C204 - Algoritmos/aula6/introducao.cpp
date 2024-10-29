#include <iostream>

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
    node * root = NULL;

    insert(root, 18);

    node * result = search(root, 18);
    if(result != NULL)
        std::cout << "Achei esse trem aqui -> " << result->info << std::endl;
    else 
        std::cout << "Num existe" << std::endl;
    return 0;
}