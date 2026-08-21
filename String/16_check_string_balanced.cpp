#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_balance(string s) {
        int n = s.length();
        int even_sum = 0;
        int odd_sum = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even_sum += s[i] - '0';
            } else {
                odd_sum += s[i] - '0';
            }
        }

        return even_sum == odd_sum;
    }
};

int main() {
    Solution sol;
    
    cout << sol.is_balance("132") << endl;
    cout << sol.is_balance("12345") << endl;
    cout << sol.is_balance("8129") << endl;
    
    return 0;
}