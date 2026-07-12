#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverse_words(string s) {
    reverse(s.begin(), s.end());

    int n = s.length();
    int i = 0;

    for (int l = 0; l < n; l++) {
        if (s[l] != '.') {
            if (i != 0) s[i++] = '.';

            int r = l;
            while (r < n && s[r] != '.') s[i++] = s[r++];

            reverse(s.begin() + i - (r - l), s.begin() + i);

            l = r;
        }
    }

    s.erase(s.begin() + i, s.end());
    return s;
}

int main() {
    cout << reverse_words("i.like.this.program.very.much") << endl;
    cout << reverse_words("..geeks..for.geeks.") << endl;
    cout << reverse_words("...home......") << endl;
    return 0;
}