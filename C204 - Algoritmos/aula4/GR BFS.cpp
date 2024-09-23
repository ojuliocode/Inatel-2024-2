#include<iostream>
#include<list>
using namespace std;

struct Aresta {
	int origem, destino, peso;	
};


bool bfs(list<Aresta> grafo[], int vertices, int origem){
    // Lista de true ou false pra ver se uma aresta ja foi visitada (pra checar se eh conexo ou desconexo)
	bool visitado[vertices];

    // Fila para o proximo a ser visitado e checar suas arestas
	list<int> fila_visitacao;

    // Iterado
	list<Aresta>::iterator it;
	
    // Inicializa visitados como false
	for(int i=0; i<vertices; i++)
		visitado[i] = false;
	
    // O primeiro a ser visitado eh o origem
	fila_visitacao.push_back(origem);

    // Origem marcado como visitado (vou visitar ele agora)
	visitado[origem] = true;
	
    // Enquanto ainda tiver aresta pra visitar
	while( !fila_visitacao.empty()){

        // Pega o cara a ser visitado mais a frente 
		int atual = fila_visitacao.front();
		cout<<atual<<endl;

        // Roda por todos os vertices desse cara (as ligacoes)
		for(it = grafo[atual].begin(); it != grafo[atual].end(); it++){

            // Pega o indice de cada destino
			int i = it->destino;

                cout << atual << " " << i << endl;
            // Checa se o destino ja foi visitado
			if(!visitado[i]){		

                // Se nao foi visitado, ele eh o proximo a ser visitado		
				fila_visitacao.push_back(i);

                // Como foi adicionado na fila de visitacao, marcamos ele como visitado
				visitado[i] = true;
			}
		}

        // Tira o da frente da visitacao (acabou de ser visitado)
		fila_visitacao.pop_front();
	}
	
	for(int i=0; i<vertices; i++){
		if(!visitado[i])
			return false;
	}

    // Se todos os vertices foram visitados, entao eh conexo
	return true;
	
}



int main(){
	int vertices, origem, destino, orientado, peso;
	
	cin>>vertices>>orientado;

	list<Aresta> grafo[vertices];
	list<Aresta>::iterator it;
    
	
		cin>>origem>>destino>>peso;
    while(!(origem == -1 && destino == -1 && peso == -1)){
		grafo[origem].push_back({origem, destino, peso});
        if(orientado == 0)
		    grafo[destino].push_back({destino, origem, peso});
		cin>>origem>>destino>>peso;
	}

	
    bfs(grafo, vertices, 0);
	
	
	return 0;
}