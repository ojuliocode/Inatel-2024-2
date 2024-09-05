
#include <iostream>

using namespace std;

// Função para particionar o array
int particionar(int array[], int inicio, int fim) {
    // Escolhe o pivô como o último elemento do intervalo
    int pivo = array[fim];
    int i = inicio - 1; // Índice do menor elemento
    
    // Reordena os elementos para que os menores estejam à esquerda do pivô e os maiores à direita
    for (int j = inicio; j <= fim - 1; j++) {
        if (array[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            // Troca array[i] com array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    // Troca o pivô com o elemento em i + 1 para colocar o pivô na posição correta
    int temp2 = array[i + 1];
    array[i + 1] = array[fim];
    array[fim] = temp2;
    
    // Retorna o índice da posição do pivô
    return i + 1;
}

// Função principal do Quicksort
void quicksort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        // Particiona o array e obtém o índice do pivô
        int indicePivo = particionar(array, inicio, fim);
        
        // Ordena recursivamente as subpartes esquerda e direita do pivô
        quicksort(array, inicio, indicePivo - 1);
        quicksort(array, indicePivo + 1, fim);
    }
}

int main() {
    // Exemplo de uso do Quicksort
    int array[] = {34, 7, 23, 32, 5, 62, 32, 78, 90, 4};
    int tamanho = sizeof(array) / sizeof(array[0]);
    
    cout << "Array antes da ordenação: ";
    for (int i = 0; i < tamanho; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    quicksort(array, 0, tamanho - 1);
    
    cout << "Array depois da ordenação: ";
    for (int i = 0; i < tamanho; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}