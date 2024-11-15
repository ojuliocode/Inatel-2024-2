#include <iostream>

using namespace std;

struct no {
    int informacao;
    no * esq;
    no * dir;
};

void inserir(no * raiz, int informacao){
        if(raiz == NULL){
            raiz = new no;
            raiz->dir = NULL;
            raiz->esq = NULL;
            raiz->informacao = informacao;
        } else {
            if(informacao < raiz->informacao)
                inserir(raiz->esq, informacao);
            else 
                inserir(raiz->dir, informacao);
        }
    
}

no * search(no * curr, int searched_info){
	if(curr == NULL)
		return NULL;
	if(curr->informacao == searched_info)
		return curr;
	if(searched_info < curr->informacao){
		return search(curr->esq, searched_info);
	} else {
		return search(curr->dir, searched_info);
	}	
}
void destruct(no * &curr){
	if(curr != NULL){
		destruct(curr->esq);
		destruct(curr->dir);
		delete curr;
		curr = NULL;
	}
}

int main(){
    no * raiz = NULL;

    int qt;

    cin >> qt;

    for(int i =0; i< qt; i++){
        int informacao;
        cin>>informacao;
        inserir(raiz, informacao);
    }

    int procurado;

    cin >> procurado;

    no * result = search(raiz, procurado);
    if(result != NULL)
        cout << "Encontrado";
    else        
        cout << "Nao encontrado";

    destruct(raiz);
    return 0;
}