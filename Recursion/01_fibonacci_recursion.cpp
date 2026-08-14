#include <iostream>
using namespace std;

// Tail recursion option that optimize time & space complexity
// Time Complexity: O(n)
// Space Complexity: O(n)*
int fibonacci(int n, int a = 0, int b = 1) {
    if (n == 0) return a;
    if (n == 1) return b;

    return fibonacci(n - 1, b, a + b);
}

int main() {
    cout << fibonacci(5) << endl;
    cout << fibonacci(3) << endl;
    cout << fibonacci(9) << endl;
    cout << fibonacci(17) << endl;
    return 0;
}