#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[101];

int solve(vector<int>& arr, int idx) {
    if (idx >= arr.size()) {
        return 0;
    }

    if (dp[idx] != -1) {
        return dp[idx];
    }

    int take = arr[idx] + solve(arr, idx + 2);
    int not_take = solve(arr, idx + 1);

    return dp[idx] = max(take, not_take);
}

int max_rob(vector<int> houses) {
    memset(dp, -1, sizeof(dp));
    return solve(houses, 0);
}

int main() {
    cout << max_rob({1, 2, 3, 4}) << endl;
    cout << max_rob({5, 9, 3}) << endl;
    cout << max_rob({2, 7, 9, 3, 1}) << endl;
    cout << max_rob({2, 1, 1, 2}) << endl;
    cout << max_rob({1, 2, 3, 1}) << endl;
    return 0;
}