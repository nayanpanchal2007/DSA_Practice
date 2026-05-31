#include <iostream>
using namespace std;

int reverse_number(int n) {
    int rev = 0;
    while (n != 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }

    return rev;
}

int main() {
    cout << reverse_number(1234) << endl;
    cout << reverse_number(78) << endl;
    cout << reverse_number(100) << endl;
    cout << reverse_number(0) << endl;
    cout << reverse_number(-3498) << endl;
    return 0;
}