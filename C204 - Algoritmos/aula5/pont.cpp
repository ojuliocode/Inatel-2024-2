#include <iostream>
using namespace std;

int main() {
    // int b , a;
    // int *p;
    // int c[5];


    // a = 5;
    // p = &a;

    // cout << p;

    int * ponteiro = new int;

    cout << *ponteiro << endl;
    *ponteiro = 5;
    cout << *ponteiro << endl;
    return 0;
}
