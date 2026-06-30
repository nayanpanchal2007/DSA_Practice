#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary_to_digit(string bin) {
    int ans = 0;
    int p = 0;

    for (int i = bin.length() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            ans += pow(2, p);
        }

        p++;
    }

    return ans;
}

int main() {
    cout << binary_to_digit("1100") << endl;
    cout << binary_to_digit("111") << endl;
    cout << binary_to_digit("1010") << endl;
    cout << binary_to_digit("1101") << endl;
    return 0;
}