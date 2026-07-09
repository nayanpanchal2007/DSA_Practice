#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count_characters(string s, char ch) {
    int cnt = 0;
    
    for (char c : s) {
        if (c == ch) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    cout << count_characters("Hello", 'o') << endl;
    cout << count_characters("Nayan", 'a') << endl;
    cout << count_characters("Robot", 'o') << endl;
    return 0;
}