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
    segmento seg1;
    segmento seg2;
        cin >> seg1.a.x >> seg1.a.y >> seg1.b.x >> seg1.b.y; 
        cin >> seg2.a.x >> seg2.a.y >> seg2.b.x >> seg2.b.y; 
    //a esquerda
    if(lado(seg1, seg2.a) != lado(seg1, seg2.b) && lado(seg2, seg1.a) != lado(seg2, seg1.b)){
        cout << "SIM";
    } else {
        cout << "NAO";
    }
    return 0;
}