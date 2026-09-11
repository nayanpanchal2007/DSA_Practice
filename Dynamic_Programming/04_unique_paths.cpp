#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int paths(int i, int j, int m, int n) {
    if (i >= m || j >= n) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (i == m - 1 && j == n - 1) {
        return 1;
    }

    int right = paths(i, j + 1, m, n);
    int down = paths(i + 1, j, m, n);

    return dp[i][j] = right + down;
}

int unique_paths(int m, int n) {
    dp.assign(m + 1, vector<int>(n + 1, -1));
    return paths(0, 0, m, n);
}

int main() {
    cout << unique_paths(5, 3) << endl;
    cout << unique_paths(3, 7) << endl;
    cout << unique_paths(3, 2) << endl;
    cout << unique_paths(51, 4) << endl;
    cout << unique_paths(10, 20) << endl;
    return 0;
}