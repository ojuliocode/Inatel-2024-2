#include<iostream>
#include<list>
using namespace std;

struct Rocha {
    string rocha, tipo;
};

struct node {
	   Rocha info;
	   node * left, * right;	
};

void insert(node * & curr, Rocha new_info){
	if(curr == NULL){
		curr = new node;
		curr->info = new_info;
		curr->left = NULL;
		curr->right = NULL;
	} else {
		if(new_info.rocha < curr->info.rocha){
			insert(curr->left, new_info);
		} else {
			insert(curr->right, new_info);
		}
	}
}

node * search(node * curr, string searched_info){
	if(curr == NULL)
		return NULL;
	if(curr->info.rocha == searched_info)
		return curr;
	if(searched_info < curr->info.rocha){
		return search(curr->left, searched_info);
	} else {
		return search(curr->right, searched_info);
	}	
}

node * point_smaller(node * &curr){
	if(curr->left == NULL){
		node * aux = curr;
		curr = curr->right;
		return aux;
	} else {
		return point_smaller(curr->left);
	}	
}

bool remove(node * &curr, string removing_info, string typeToRemove){
	if(curr == NULL)
		return false;
	if(curr->info.rocha == removing_info && curr->info.tipo == typeToRemove){
		node * aux = curr;
		if(curr->left == NULL)
			curr = curr->right;
		else if(curr->right == NULL)
			curr = curr->left;
		else {
			aux = point_smaller(curr->right);
			curr->info = aux->info;
		}
		delete aux;
		return  true;
	} else if(removing_info < curr->info.rocha){
		return remove(curr->left, removing_info, typeToRemove);
	} else {
		return remove(curr->right, removing_info, typeToRemove);
	}	
}


void destruct(node * &curr){
	if(curr != NULL){
		destruct(curr->left);
		destruct(curr->right);
		delete curr;
		curr = NULL;
	}
}



int main(){
    node * raiz = NULL;
    int opcao;
    string rocha, tipo;
    node * buscado;
    string rochaPraRemover, rochaPraBuscar, tipoPraRemover;
    bool removed;

    cin >> opcao;

    while(opcao != 0){
        switch (opcao)
        {
        case 1:
            cin.ignore();
            getline(cin, rocha);
            getline(cin, tipo);
            insert(raiz, {rocha, tipo});
            break;
        case 2:
            cin.ignore();
            getline(cin, rochaPraBuscar);
            buscado = search(raiz, rochaPraBuscar); 
            if(buscado == NULL)
                cout << "Rocha nao encontrada" << endl;
            else {
                cout << "Nome: " << buscado->info.rocha << endl;
                cout << "Tipo: " << buscado->info.tipo << endl;
            }
            break;
        case 3:
            cin.ignore();
            getline(cin, rochaPraRemover);
            getline(cin, tipoPraRemover);
            removed = remove(raiz, rochaPraRemover, tipoPraRemover);
            if(removed)
                cout << "Rocha removida com sucesso" << endl;
            else 
                cout << "Rocha nao encontrada para remocao" << endl;
            break;
        default:
            break;
        }
        cin >> opcao;
    }
    destruct(raiz);
}