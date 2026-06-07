#include <iostream>
using namespace std;

int sum_1_to_n(int n) {
    if (n <= 0) return 0;
    
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

int main() {
    cout << sum_1_to_n(10) << endl;
    cout << sum_1_to_n(4) << endl;
    return 0;
}