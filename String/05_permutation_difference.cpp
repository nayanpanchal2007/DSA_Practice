#include <iostream>
using namespace std;

int permutation_diff(string s, string t) {
    int n = s.length();
    int m = t.length();

    int diff = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j]) {
                diff += abs(j - i);
            }
        }
    }

    return diff;
}

int main() {
    cout << permutation_diff("abc", "bac") << endl;
    cout << permutation_diff("abcde", "edbac") << endl;
    cout << permutation_diff("nayan", "ayann") << endl;
    return 0;
}