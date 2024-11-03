#include <iostream>

using namespace std;

int main(){
    int arr[10];
    int * ptr;

    for(int i = 0; i<10; i++){
        arr[i] = i;
    }

    ptr = arr;

    cout << *ptr + 1;
    return 0;
}