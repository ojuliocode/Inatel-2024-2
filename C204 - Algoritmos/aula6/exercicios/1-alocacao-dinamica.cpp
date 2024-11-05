#include <iostream>
#include <iomanip>

using namespace std;

struct notasStruct {
    int nota1,nota2,nota3,nota4,media;
};
int main(){
    notasStruct * notas = new notasStruct;
    cin >> notas->nota1;
    cin >> notas->nota2;
    cin >> notas->nota3;
    cin >> notas->nota4;
    notas->media = (notas->nota1 + notas->nota2 + notas->nota3 + notas->nota4)/4;
    cout << fixed << setprecision(2) << notas->media;
    return 0;
}