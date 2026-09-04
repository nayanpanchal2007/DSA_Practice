#include <bits/stdc++.h>
using namespace std;

int number_of_stairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    cout << number_of_stairs(5) << endl; // Output: 8
    cout << number_of_stairs(10) << endl; // Output: 89
    cout << number_of_stairs(20) << endl; // Output: 10946
    cout << number_of_stairs(30) << endl; // Output: 1346269
    return 0;
}