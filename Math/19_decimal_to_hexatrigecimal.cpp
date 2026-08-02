#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string decimal_to_hexatrigecimal(int num) {
    string hex_g = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans = "";

    while (num != 0) {
        ans = hex_g[num % 36] + ans;
        num /= 36;
    }

    return ans;
}

int main() {
    cout << decimal_to_hexatrigecimal(45) << endl;
    cout << decimal_to_hexatrigecimal(71) << endl;
    cout << decimal_to_hexatrigecimal(72) << endl;
    cout << decimal_to_hexatrigecimal(100) << endl;
    return 0;
}