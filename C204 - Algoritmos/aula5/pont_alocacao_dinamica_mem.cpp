#include <iostream>
#include <iomanip> // necessary library for using setprecision

using namespace std;

struct notas {
    float nota1,nota2,nota3,nota4,media;
};
int main() {
    notas *n = new notas;
    cin >> n->nota1;
    cin >> n->nota2;
    cin >> n->nota3;
    cin >> n->nota4;
    n->media = (n->nota1 + n->nota2 + n->nota3 + n->nota4) / 4;
    cout << fixed << setprecision(2) << n->media;
    return 0;
}