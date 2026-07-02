#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_valid_palindrome(string& s) {
    string str = "";

    for (char c : s) {
        c = tolower(c);
        
        if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
            str += c;
        }
    }

    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";
    
    cout << (is_valid_palindrome(s1) ? "true" : "false") << endl;
    cout << (is_valid_palindrome(s2) ? "true" : "false") << endl;
    cout << (is_valid_palindrome(s3) ? "true" : "false") << endl;
    return 0;
}