#include<iostream>
#include<list>
using namespace std;

struct Filme {
    string nome,genero;
    int duracao, classificacao, ano;
};

struct node {
	   Filme filme;
	   node * left, * right;	
};

void insert(node * & curr, Filme new_filme){
	if(curr == NULL){
		curr = new node;
		curr->filme = new_filme;
		curr->left = NULL;
		curr->right = NULL;
	} else {
		if(new_filme.nome < curr->filme.nome){
			insert(curr->left, new_filme);
		} else {
			insert(curr->right, new_filme);
		}
	}
}

node * search(node * curr, string nomeFilme){
	if(curr == NULL)
		return NULL;
	if(curr->filme.nome == nomeFilme)
		return curr;
	if(nomeFilme < curr->filme.nome){
		return search(curr->left, nomeFilme);
	} else {
		return search(curr->right, nomeFilme);
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
    string nome,genero, nomeProcurado;
    int duracao, classificacao, ano;
    Filme filme;
    node * procurado;
    cin >> opcao;
    while(opcao != 0){
        switch (opcao)
        {
        case 1:
            cin.ignore();
            getline(cin, nome);
            getline(cin, genero);
            cin >> duracao;
            cin >> classificacao;
            cin >> ano;
            filme = {nome, genero, duracao, classificacao, ano};
            insert(raiz, filme);
            break;
        case 2:
            cin.ignore();
            getline(cin, nomeProcurado);
            procurado = search(raiz, nomeProcurado);
            if(procurado == NULL)
                cout << "Filme nao encontrado" << endl;
            else {
                cout << "Nome: " << procurado->filme.nome << endl;
                cout << "Genero: " << procurado->filme.genero << endl;
                cout << "Duracao: " << procurado->filme.duracao << " mins" << endl;
                cout << "Classificacao: " << procurado->filme.classificacao << endl;
                cout << "Ano: " << procurado->filme.ano << endl;
            }
            break;
        case 0:
            break;
        default:
            cout << "Operacao invalida" << endl;
            break;
        }
        
        cin >> opcao;
    }
    destruct(raiz);
	return 0;
}