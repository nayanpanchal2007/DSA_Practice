#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

void print_fib(int n) {
    cout << "Fibonacci for (n=" << n << "): ";
    for (int i = 0; i < n; i++) {
        cout << fib(i) << " ";
    }
    cout << endl;
}

int main() {
    print_fib(5);
    print_fib(7);
    print_fib(10);
    print_fib(-3);
    return 0;
}