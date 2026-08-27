#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sub;

void subarrays(vector<int>& arr, int start, int end) {
    if (end == arr.size()) {
        return;
    }

    if (start > end) {
        subarrays(arr, 0, end + 1);
        return;
    }

    vector<int> curr;

    for (int i = start; i <= end; i++) {
        curr.push_back(arr[i]);
    }

    sub.push_back(curr);
    subarrays(arr, start + 1, end);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    subarrays(arr, 0, 0);

    for (auto& v : sub) {
        for (int& x : v) {
            cout << x << " ";
        }

        cout << endl;
    }
    return 0;
}