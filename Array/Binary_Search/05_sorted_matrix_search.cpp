#include <bits/stdc++.h>
using namespace std;

bool _binary_search(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();

    int left = 0;
    int right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int row = mid / n;
        int col = mid % n;

        if (mat[row][col] == target) {
            return true;
        } else if (mat[row][col] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << boolalpha;
    cout << _binary_search(mat, 3) << endl;
    cout << _binary_search(mat, 13) << endl;
    cout << _binary_search(mat, 15) << endl;
    cout << _binary_search(mat, 7) << endl;
    cout << _binary_search(mat, 10) << endl;
    return 0;
}