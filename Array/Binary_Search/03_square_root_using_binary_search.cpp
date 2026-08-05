#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int square_root(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return n;

    int low = 1;
    int high = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid == n / mid) {
            return mid;
        } else if (mid < n / mid) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    cout << square_root(16) << endl;
    cout << square_root(-1) << endl;
    cout << square_root(1) << endl;
    cout << square_root(81) << endl;
    cout << square_root(9) << endl;
    return 0;
}