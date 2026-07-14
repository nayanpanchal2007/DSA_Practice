#include <iostream>
using namespace std;

void sort_string(string& s) {
    int n = s.length();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

int main() {
    string s = "cbafed";
    sort_string(s);
    cout << s << endl;
    return 0;
}