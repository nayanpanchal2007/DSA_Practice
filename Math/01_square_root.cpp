#include <iostream>
using namespace std;

int square_root(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) {
            return i;
        }
    }

    return -1;
}

int main() {
    cout << square_root(1) << endl;
    cout << square_root(4) << endl;
    cout << square_root(9) << endl;
    cout << square_root(15) << endl;
    return 0;
}