#include <iostream>
#include <stack>
using namespace std;

bool is_valid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;

            if (c == ')' && st.top() != '(' || c == ']' && st.top() != '[' || c == '}' && st.top() != '{') {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}

int main() {
    cout << is_valid("{}()[]") << endl;
    cout << is_valid("()[") << endl;
    cout << is_valid("[({])") << endl;
    cout << is_valid("[({(([]))})]") << endl;
    return 0;
}