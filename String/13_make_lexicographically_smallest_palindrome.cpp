#include <iostream>
using namespace std;

string lexicographically_smallest_palindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] < s[right]) {
            s[right] = s[left];
        } else if (s[left] > s[right]) {
            s[left] = s[right];
        }

        left++;
        right--;
    }

    return s;
}

int main() {
    cout << lexicographically_smallest_palindrome("abcd") << endl;
    cout << lexicographically_smallest_palindrome("egbfe") << endl;
    cout << lexicographically_smallest_palindrome("rqlsqb") << endl;
    return 0;
}