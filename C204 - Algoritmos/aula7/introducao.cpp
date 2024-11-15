#include <iostream>

using namespace std;


struct ponto {
    int x, y;
};

struct segmento {
    ponto a, b;
};

float area_triangulo(ponto a, ponto b, ponto c){
    return (
        a.x * b.y - a.y * b.x + 
        a.y * c.x - a.x * c.y +
        b.x * c.y - b.y * c.x 
    )/2.0;
}

// Sentido horario negativo
// Sentido anti horario positivo
int lado(segmento ab, ponto c){
    float area = area_triangulo(ab.a, ab.b, c);
    if(area < 0)
        return -1;
    if(area > 0)
        return 1;
    return 0;
}

int main(){


    return 0;
}