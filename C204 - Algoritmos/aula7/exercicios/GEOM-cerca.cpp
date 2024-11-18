#include <iostream>
#include <cmath>

using namespace std;

struct Ponto {
    int x;
    int y;
};

float distanciaEntrePontos(Ponto p1, Ponto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    int qtPontos;
    cin >> qtPontos;

    Ponto pontos[qtPontos];

    for (int i = 0; i < qtPontos; i++) {
        cin >> pontos[i].x >> pontos[i].y;
    }

    float totalDistance = 0;

    for (int i = 0; i < qtPontos; i++) {
        totalDistance += distanciaEntrePontos(pontos[i], pontos[(i + 1) % qtPontos]);
    }

    int perimetro = ceil(totalDistance);

    cout << perimetro << endl;

    return 0;
}