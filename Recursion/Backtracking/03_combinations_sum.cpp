#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int target, vector<int>& curr, int idx, vector<vector<int>>& ans) {
    int sum = accumulate(curr.begin(), curr.end(), 0);

    if (sum == target) {
        ans.push_back(curr);
        return;
    }

    if (sum > target || idx == arr.size()) {
        return;
    }

    curr.push_back(arr[idx]);
    solve(arr, target, curr, idx, ans);
    curr.pop_back();

    solve(arr, target, curr, idx + 1, ans);
}

vector<vector<int>> combination_sum(vector<int>& arr, int target) {
    vector<int> curr;
    vector<vector<int>> ans;
    solve(arr, target, curr, 0, ans);
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 7};
    int target = 7;

    vector<vector<int>> result = combination_sum(arr, target);

    for (auto& v : result) {
        for (auto& x : v) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}