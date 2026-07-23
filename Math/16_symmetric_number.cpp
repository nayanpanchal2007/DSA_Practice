#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_symmetric(int n) {
    string s = to_string(n);
    int sz = s.length();

    if (sz % 2 != 0) return false;

    int left = 0, right = 0;

    for (int i = 0; i < sz / 2; i++) {
        left += s[i] - '0';
    }

    for (int i = sz / 2; i < sz; i++) {
        right += s[i] - '0';
    }
    
    return left == right;
}

void print_symmetric_numbers(int low, int high) {
    for (int i = low; i <= high; i++) {
        if (is_symmetric(i)) {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main() {
    print_symmetric_numbers(1, 100);
    print_symmetric_numbers(1200, 1230);
    return 0;
}