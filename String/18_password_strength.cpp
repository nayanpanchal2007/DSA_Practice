#include <bits/stdc++.h>
using namespace std;

int password_strength(string s) {
    unordered_set<char> seen;
    int ans = 0;

    for (char& ch : s) {
        if (seen.count(ch)) continue;
        
        if (islower(ch)) ans += 1;
        else if (isupper(ch)) ans += 2;
        else if (isdigit(ch)) ans += 3;
        else ans += 5;

        seen.insert(ch);
    }

    return ans;
}

int main() {
    cout << password_strength("aA1!") << endl;
    cout << password_strength("bbB11#") << endl;
    cout << password_strength("vqztn2Z") << endl;
    return 0;
}