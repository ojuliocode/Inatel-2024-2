#include <iostream>

using namespace std;

int main() {
    int *p;
    int x[10];
    p = x;
    cout << (int)p << endl;
    p = &x[1];
    cout << (int)p;
    return 0;
}
