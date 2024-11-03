#include <iostream>

using namespace std;

int main(){
    int variable;
    int * pointer;

    pointer = &variable;
    *pointer = 5;

    cout << variable;
    return 0;
}