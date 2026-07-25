#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count_set_bits(int n) {
    int cnt = 0;

    while (n != 0) {
        if (n & 1 == 1) cnt++;
        n >>= 1;
    }

    return cnt;
}

int main() {
    cout << count_set_bits(2) << endl;
    cout << count_set_bits(10) << endl;
    cout << count_set_bits(15) << endl;
    return 0;
}