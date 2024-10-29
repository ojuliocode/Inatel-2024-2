#include <iostream>

using namespace std;

int main(){
    float x[3];
    float y;
    float *p;
    y = 4;

    // p recebe o endereco de y 
    p = &y;
    for(int i = 0; i < 3; i++){
        // Multiplicando conteudo de y (4) por i
        // 4 * 0, 4 * 1 e 4 * 2
        x[i] = *p*i;
        cout << x[i] << " ";
    }
    return 0;
}