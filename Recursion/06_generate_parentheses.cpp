#include <bits/stdc++.h>
using namespace std;

vector<string> par;

bool is_valid(string& s) {
    int balance = 0;

    for (char& ch : s) {
        if (ch == '(') {
            balance++;
        } else {
            balance--;

            if (balance < 0) {
                return false;
            }
        }
    }

    return balance == 0;
}

void generate_parentheses(string& curr, int n) {
    if (curr.length() == 2 * n) {
        if (is_valid(curr)) {
            par.push_back(curr);
        }

        return;
    }

    curr.push_back('(');
    generate_parentheses(curr, n);
    curr.pop_back();

    curr.push_back(')');
    generate_parentheses(curr, n);
    curr.pop_back();
}

int main() {
    int n = 3;
    string curr = "";

    generate_parentheses(curr, n);

    for (string& s : par) {
        cout << s << endl;
    }

    return 0;
}