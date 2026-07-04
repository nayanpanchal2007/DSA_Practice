#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverse_k(string s, int k) {
    reverse(s.begin(), s.begin() + k);
    return s;
}

int main() {
    cout << reverse_k("hello", 2) << endl;
    cout << reverse_k("world", 3) << endl;
    cout << reverse_k("c++ is programming language", 18) << endl;
    return 0;
}