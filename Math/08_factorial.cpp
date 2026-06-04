#include <iostream>
#include <limits.h>
using namespace std;

long long factorial(int n) {
    if (n < 0) return INT_MIN;
    if (n == 0 || n == 1) return 1; 

    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }

    return ans;
}

int main() {
    cout << factorial(5) << endl;
    cout << factorial(10) << endl;
    cout << factorial(6) << endl;
    cout << factorial(-19) << endl;
    cout << factorial(0) << endl;
    return 0;
}