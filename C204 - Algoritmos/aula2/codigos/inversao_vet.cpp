
#include <iostream>

using namespace std;

    int inversoes = 0;
// Função para particionar o array
int particionar(int array[], int inicio, int fim) {
    // Escolhe o pivô como o último elemento do intervalo
    int pivo = array[fim];
    int i = inicio - 1; // Índice do menor elemento
    
    // Reordena os elementos para que os menores estejam à esquerda do pivô e os maiores à direita
    cout << "-------------" << endl;
    for (int j = inicio; j <= fim - 1; j++) {
        if (array[j] <= pivo) {
            i++;
            cout << "Incremente i" << endl;
            cout << array[j] << " e " << pivo << endl;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            inversoes++;
        } else {
            cout << "Nao incrementa i" << endl;
        }
    }
    
    // Troca o pivô com o elemento em i + 1 para colocar o pivô na posição correta
    if(array[i+1] != array[fim])
        inversoes++;
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
    int n;
    cin >> n;
    int arr[n];
    
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << endl;
    
    quicksort(arr, 0, tamanho - 1);
    
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << inversoes;
    return 0;
}