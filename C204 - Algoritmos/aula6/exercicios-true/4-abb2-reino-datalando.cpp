#include <iostream>

using namespace std;

struct Node {
    Node * leftPointer;
    Node * rightPointer;
    int nodeData;
};

void insertInTree(Node *& currentNode, int dataToBeInserted){
    if(currentNode == NULL){
        currentNode = new Node;
        currentNode->leftPointer = NULL;
        currentNode->rightPointer = NULL;
        currentNode->nodeData = dataToBeInserted;
    } else {
        if(dataToBeInserted >= currentNode->nodeData){
            insertInTree(currentNode->rightPointer, dataToBeInserted);
        } else {
            insertInTree(currentNode->leftPointer, dataToBeInserted);
        }
    }
}

void preOrder(Node *& currentNode){
    if(currentNode != NULL){
        preOrder(currentNode->leftPointer);
        cout << currentNode->nodeData << endl;
        preOrder(currentNode->rightPointer);
    }
}

bool search(Node *& currentNode, int dataToBeSearched){
    if(currentNode == NULL)
        return false;
    
    if(dataToBeSearched == currentNode->nodeData)
        return true;
    
    if(dataToBeSearched >= currentNode->nodeData)
        return search(currentNode->rightPointer, dataToBeSearched);
        
    return search(currentNode->leftPointer, dataToBeSearched);
}

Node * treePointSmaller(Node *& currentNode){
    Node * t = currentNode;
    if(currentNode->leftPointer == NULL){
        currentNode = currentNode->rightPointer;
        return t;
    } else {
        return treePointSmaller(currentNode->leftPointer);
    }
}


bool remove(Node *& p, int x){
    Node * t;
    if(p == NULL)
        return false;
    if(x == p->nodeData){
        t = p;
        if(p->leftPointer == NULL)
            p = p->rightPointer;
        else if(p->rightPointer == NULL)
            p = p->leftPointer;
        else {
            t = treePointSmaller(p->rightPointer);
            p->nodeData = t->nodeData;
        }

        delete t;
        return true;
    } else if (x < p->nodeData)
        return remove(p->leftPointer, x);
    else
        return remove(p->rightPointer, x);
}

int main(){
    Node * root = NULL;
    int qt;

    cin >> qt;

    for(int i =0; i<qt; i++){
        char opt;
        int item;

        cin >> opt;
        cin >> item;

        switch (opt)
        {
        case 'i':
            insertInTree(root, item);
            break;
        case 'r':
            remove(root, item);
            break;
        default:
            bool found = search(root, item);
            if(found)
                cout << "Sim";
            else 
                cout << "Nao";
            break;
        }
    }
    return 0;
}