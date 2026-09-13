#include <bits/stdc++.h>
using namespace std;

bool is_same_freq(string s) {
    vector<int> freq(26, 0);

    for (char& ch : s) {
        freq[ch - 'a']++;
    }

    unordered_set<int> st;
    
    for (int& f : freq) {
        if (f != 0) {
            st.insert(f);
        }
    }

    return st.size() == 1;
}

string check(string s) {
    if (is_same_freq(s)) {
        return "True";
    } 

    return "False";
}

int main() {
    cout << check("abab") << endl;
    cout << check("abcd") << endl;
    cout << check("aabc") << endl;
    cout << check("xppnjp") << endl;
    cout << check("nnyayaayn") << endl;

    return 0;
}