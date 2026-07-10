#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void freq_counter(string s) {
    map<char, int> freq;
    
    for (char c : s) {
        freq[c]++;
    }
    
    for (auto [key, val] : freq) {
        cout << key << " = " << val << endl;
    }

    cout << endl;
}

int main() {
    freq_counter("C++ is a Object Oriented Programming Language.");
    
    return 0;
}