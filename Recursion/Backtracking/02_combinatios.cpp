#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, vector<int>& curr, int val, vector<vector<int>>& ans) {
    if (curr.size() == k) {
        ans.push_back(curr);
        return;
    }

    if (val > n) return;

    curr.push_back(val);
    solve(n, k, curr, val + 1, ans);
    curr.pop_back();

    solve(n, k, curr, val + 1, ans);
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> curr;
    solve(n, k, curr, 1, ans);
    return ans;
}

int main() {
    int n = 4;
    int k = 2;

    for (auto v : combine(n, k)) {
        for (int x : v) {
            cout << x << " ";
        }

        cout << endl;
    }
    
    return 0;
}