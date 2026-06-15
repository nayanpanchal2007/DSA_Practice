#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;

void pascal_triangle(int n) {
    dp.resize(n + 1, vector<int>(n + 1, 1));
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else if (i > 0 && j > 0) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
}

int main() {
    int n = 4;

    pascal_triangle(n);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}