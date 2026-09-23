#include <bits/stdc++.h>
using namespace std;

string backspace(string s) {
    string ans = "";

    for (char& ch : s) {
        if (ch == '*') {
            if (!ans.empty()) {
                ans.pop_back();
            }
        } else {
            ans.push_back(ch);
        }
    }

    return ans;
}

int main() {
    vector<string> tests = {
        "abc",
        "a*b",
        "ab*c",
        "abc*",
        "abc**",
        "abc***",
        "*",
        "**",
        "***abc",
        "a**",
        "a***",
        "*a*b*c*",
        "abc**d*",
        "a*b*c",
        "leet**code",
        "abc*d**ef",
        "a**b***c"
    };

    for (string s : tests) {
        cout << "Input: \"" << s << "\""
             << " -> Output: \"" << backspace(s) << "\"\n";
    }

    return 0;
}