//
// Created by julio on 9/5/2024.
//

#include <iostream>

using namespace std;

int potencia(int base, int expoente) {
    if(expoente == 0)
        return 1;

    return base * potencia(base, expoente-1);
}

int main() {
    cout << potencia(2, 5);
    return 0;
}