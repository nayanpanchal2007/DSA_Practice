#include <iostream>
#include <stack>
using namespace std;

int calculate(string s) {
    stack<int> st;
    
    int number = 0;
    int ans = 0;
    int sign = 1;
    
    for (char ch : s) {
        if (isdigit(ch)) {
            number = number * 10 + (ch - '0');
        } else if (ch == '+') {
            ans += sign * number;
            number = 0;
            sign = 1;
        } else if (ch == '-') {
            ans += sign * number;
            number = 0;
            sign = -1;
        } else if (ch == '(') {
            st.push(ans);
            st.push(sign);
            ans = 0;
            sign = 1;
        } else if (ch == ')') {
            ans += sign * number;
            number = 0;
            ans *= st.top();
            st.pop();
            ans += st.top();
            st.pop();
        }
    }

    ans += sign * number;
    return ans;
}

int main() {
    string s;
    cout << "Enter your expression: ";
    getline(cin, s);

    int result = calculate(s);

    cout << "Result = " << result << endl;
    return 0;
}