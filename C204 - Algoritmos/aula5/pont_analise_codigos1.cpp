#include <iostream>

using namespace std;

int main(){
    int x, y;
    int *p, *q;
    x = 2;
    y = 3;
    p = &x;
    *p++;
    // 6 is output
    cout << *p + y << endl;
    return 0;
}