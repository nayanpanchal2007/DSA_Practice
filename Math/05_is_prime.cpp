#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << is_prime(5) << endl;
    cout << is_prime(10) << endl;
    cout << is_prime(-3) << endl;
    cout << is_prime(0) << endl;
    cout << is_prime(23) << endl;
    return 0;
}