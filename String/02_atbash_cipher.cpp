#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * swap numbers with reverse characters means:
 * a -> z
 * b -> y
 * c -> x
 * ...
 * ...
 * z -> a
 */

string atbash_cipher(string s) {
    string ans = "";
    
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            ans += 'z' - (c - 'a');
        } else if (c >= 'A' && c <= 'Z') {
            ans += 'Z' - (c - 'A');
        } else {
            ans += c;
        }
    }

    return ans;
}
 
int main() {
    cout << atbash_cipher("hello world") << endl;
    cout << atbash_cipher("abc") << endl;
    cout << atbash_cipher("xyz") << endl;
    cout << atbash_cipher("programming") << endl;
    return 0;
}