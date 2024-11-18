#include <iostream>
#include <cmath>

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
double distancia(ponto p1, ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
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
    ponto pontos[3];
    for(int i = 0 ;  i < 3; i++){
        cin >> pontos[i].x >> pontos[i].y;
    }

    float area = area_triangulo(pontos[0], pontos[1], pontos[2]);
    cout << area;
    return 0;
}