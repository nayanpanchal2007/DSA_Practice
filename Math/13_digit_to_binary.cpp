#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string digit_to_binary(int n) {
    string ans = "";

    while (n != 0) {
        int rem = n % 2;
        ans = to_string(rem) + ans;
        n /= 2;
    }

    return ans;
}

int main() {
    cout << digit_to_binary(3) << endl;
    cout << digit_to_binary(8) << endl;
    cout << digit_to_binary(10) << endl;
    cout << digit_to_binary(14) << endl;
    return 0;
}