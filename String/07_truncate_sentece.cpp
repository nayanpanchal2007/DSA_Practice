#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string truncate_sentence(string s, int k) {
    int space_cnt = 0;
    string ans = "";

    for (char c : s) {
        if (c == ' ') {
            if (++space_cnt == k) break;
        }

        ans += c;
    }

    return ans;
}

int main() {
    cout << truncate_sentence("Hello how are you Contestant", 4) << endl;
    cout << truncate_sentence("What is the solution to this problem", 4) << endl;
    cout << truncate_sentence("chopper is not a tanuki", 5) << endl;
    return 0;
}