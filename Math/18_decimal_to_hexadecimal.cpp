#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string decimal_to_hexadecimal(int n) {
    string hex = "0123456789ABCDEF";
    string ans = "";

    while (n != 0) {
        ans = hex[n % 16] + ans;
        n /= 16;
    }
    
    return ans;
}

int main() {
    cout << decimal_to_hexadecimal(10) << endl;
    cout << decimal_to_hexadecimal(25) << endl;
    cout << decimal_to_hexadecimal(99) << endl;
    cout << decimal_to_hexadecimal(30) << endl;
    cout << decimal_to_hexadecimal(50) << endl;
    cout << decimal_to_hexadecimal(77) << endl;
    return 0;
}