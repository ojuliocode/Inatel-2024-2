#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    vector<int> test;
    for (int i = 0; i < 4; i++) {
        int temp;
        cin >> temp;
        test.push_back(temp);
    }

    for (int i = 0; i < 4; ++i) {
        cout << test.back() << endl;
        test.pop_back();
    }


    return 0;
}
