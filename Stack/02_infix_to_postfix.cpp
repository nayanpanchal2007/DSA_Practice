#include <bits/stdc++.h>
#include <print>
using namespace std;

int precedence(char& ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return 0;
}

string infix_to_postfix(string& infix) {
    string postfix = "";
    stack<char> st;

    for (char& ch : infix) {
        if (isspace(ch)) continue;
               
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && st.top() != '(' &&
                    (precedence(st.top()) > precedence(ch) || 
                    (precedence(st.top()) == precedence(ch) && ch != '^'))) {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infix_to_postfix(infix);
    cout << "Postfix expression: " << postfix << "\n";
    return 0;
}