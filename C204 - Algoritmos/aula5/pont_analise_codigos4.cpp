#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    int *p;

    // p é endereço de a
    p = &a;

    // a = 2
    *p = 2;

    // p é endereço de b
    p=&b;

    // p = 3
    *p = 3;
    c = 0;

    // c = 0 + 3
    c = c+*p;

    // p é endereço de a
    p = &a;

    // c = 3 + 2 = 5
    c = c+*p;

    cout << c << endl;
    return 0;
}
