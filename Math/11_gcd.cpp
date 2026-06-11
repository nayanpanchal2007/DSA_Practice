#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main() {
    cout << gcd(10, 5) << endl;
    cout << gcd(9, 8) << endl;
    cout << gcd(-18, 26) << endl;
    cout << gcd(0, -8) << endl;
    cout << gcd(4, gcd(8, 16)) << endl;
    return 0;
}