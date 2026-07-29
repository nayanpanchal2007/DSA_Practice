#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void permute(string& s, int index = 0) {
    int n = s.length();
    
    if (index == n) {
        cout << s << endl;
        return;
    }

    for (int i = index; i < n; i++) {
        swap(s[i], s[index]);
        permute(s, index + 1);
        swap(s[i], s[index]);
    }
}

int main() {
    string s = "abc";
    permute(s);
    return 0;
}