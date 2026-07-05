#include <iostream>
using namespace std;

int balanced_string_split(string s) {
    int balance = 0;
    int ans = 0;

    for (char c : s) {
        if (c == 'R') {
            balance++;
        } else {
            balance--;
        }

        if (balance == 0) ans++;
    }

    return ans;
}

int main() {
    cout << balanced_string_split("RLRRLLRLRL") << endl;
    cout << balanced_string_split("RLRRRLLRLL") << endl;
    cout << balanced_string_split("LLLLRRRR") << endl;
    return 0;
}