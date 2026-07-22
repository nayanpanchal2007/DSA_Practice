/*
***Clear Digits***

You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.

 

Example 1:

Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.

Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".

 

Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string clear_digits(string s) {
    stack<char> st;

    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            st.push(c);
        } else if (!st.empty() && c >= '0' && c <= '9') {
            st.pop();
        }
    }

    string ans = "";

    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}

int main() {
    cout << clear_digits("abc") << endl;
    cout << clear_digits("cb34") << endl;
    cout << clear_digits("ad3f9ll") << endl;
    return 0;
}