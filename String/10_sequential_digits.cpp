#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> sequential_digits_in_range(int low, int high) {
    string s = "123456789";

    string l = to_string(low);
    string h = to_string(high);

    vector<int> ans;

    for (int i = l.length(); i <= h.length(); i++) {
        for (int j = 0; j <= 9 - i; j++) {
            string n = s.substr(j, i);
            int num = stoi(n);

            if (num >= low && num <= high) {
                ans.push_back(num);
            }
        }
    }

    return ans;
}

int main() {
    for (int x : sequential_digits_in_range(100, 300)) cout << x << " ";
    cout << endl;

    for (int x : sequential_digits_in_range(1000, 13000)) cout << x << " ";
    cout << endl;

    for (int x : sequential_digits_in_range(2000, 3000)) cout << x << " ";
    cout << endl;

    return 0;
}