#include <bits/stdc++.h>
using namespace std;

vector<int> smaller_numbers_than_current(vector<int>& nums) {
    vector<int> freq(101, 0);

    for (int& num : nums) {
        freq[num]++;
    }

    for (int i = 1; i <= 100; i++) {
        freq[i] += freq[i - 1];
    }

    vector<int> ans;
    
    for (int& num : nums) {
        if (num == 0) {
            ans.push_back(0);
        } else {
            ans.push_back(freq[num - 1]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> tests = {
        {8,1,2,2,3},
        {6,5,4,8},
        {7,7,7,7}
    };

    for (auto& test : tests) {
        vector<int> ans = smaller_numbers_than_current(test);

        for (int& x : ans) {
            cout << x << " ";
        }

        cout << "\n";
    }

    return 0;
}