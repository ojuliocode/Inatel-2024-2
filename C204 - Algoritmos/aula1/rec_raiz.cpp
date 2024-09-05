//
// Created by julio on 9/5/2024.
//

#include <iomanip>
#include <iostream>

using namespace std;

float raiz(float x, float x0, float err) {
    float erroChecagem = abs((x0 * x0) - x);
    if(erroChecagem <= err)
        return x0;

    float novoX0 = (((x0 * x0) + x) / (2*x0));
    return raiz(x, novoX0, err);
}

int main() {
    float x, x0, err;
    cin >> x >> x0 >> err;

    cout << setprecision(4) << raiz(x,x0,err);

    return 0;
}
