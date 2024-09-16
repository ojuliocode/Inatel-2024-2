#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> test;
    for (int i = 0; i < 4; i++) {
        int temp;
        cin >> temp;
        test.push_back(temp);
    }

    for (int i = 0; i < 4; ++i) {
        cout << test.front() << " ";
        test.pop_front();
    }


    return 0;
}
