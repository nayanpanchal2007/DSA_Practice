#include <iostream>
using namespace std;

double square_root(double n) {
    if (n < 0) {
        return -1;
    }

    double low = 0;
    double high = (n >= 1) ? n : 1;

    while (high - low > 1e-7) {
        double mid = low + (high - low) / 2;

        if (mid * mid < n) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    cout << square_root(2) << endl;
    cout << square_root(3) << endl;
    cout << square_root(4) << endl;
    cout << square_root(7) << endl;
    cout << square_root(16) << endl;
    return 0;
}