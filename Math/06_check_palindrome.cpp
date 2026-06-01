#include <iostream>
using namespace std;

bool is_palindrome(int n) {
    string orig = to_string(n);
    int left = 0;
    int right = orig.length() - 1;

    while (left < right) {
        if (orig[left] != orig[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    cout << is_palindrome(121) << endl;
    cout << is_palindrome(1975) << endl;
    cout << is_palindrome(-45) << endl;
    cout << is_palindrome(-98989) << endl;
    cout << is_palindrome(5035) << endl;
    cout << is_palindrome(123321) << endl;
    return 0;
}