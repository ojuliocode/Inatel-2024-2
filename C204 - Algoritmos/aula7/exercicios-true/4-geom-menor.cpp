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
    int numPontos;
    cin >> numPontos;
    
    ponto pontosinteress[numPontos];

    for(int i = 0; i< numPontos; i++){
        cin >> pontosinteress[i].x >> pontosinteress[i].y;
    }

    ponto procurado;
    cin >> procurado.x >> procurado.y;
    ponto repetidas[numPontos];
    for(int i = 0; i< numPontos; i++){
        repetidas[i] = {-1, -1};
    }
    int distancias[numPontos];
    int menor = 10000;
    for(int i = 0; i< numPontos; i++){
        distancias[i] = distancia(pontosinteress[i], procurado);
        if(distancias[i] < menor){
            menor = distancias[i];
        }
    }

    ponto menorpont = {-1, -1};

    bool achouTruncado = false;
    for(int i = 0; i< numPontos; i++){
        if(distancias[i] == menor && achouTruncado == false){
            menorpont = pontosinteress[i];
            for(int j = numPontos - 1; j > i; j--){
                if(distancias[j] == menor){
                    achouTruncado = true;
                    if(pontosinteress[j].x < pontosinteress[i].x){
                        menorpont = pontosinteress[j];
                    } else if (pontosinteress[j].x > pontosinteress[i].x){
                        menorpont = pontosinteress[i];
                    } else if (pontosinteress[j].y < pontosinteress[i].y) {
                        menorpont = pontosinteress[j];
                    } else {
                        menorpont = pontosinteress[i];
                    }
                } 
            }
        }
    }

    cout << menorpont.x << " " << menorpont.y << endl;
    return 0;
}