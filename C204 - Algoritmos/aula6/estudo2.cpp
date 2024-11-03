#include <iostream>

using namespace std;

int main(){
    int arr[10];
    int * ptr;

    for(int i = 0; i<10; i++){
        arr[i] = i*1000;
    }

    ptr = arr;

    cout << *(ptr + 2);
    return 0;
}