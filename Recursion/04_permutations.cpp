#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> per;

void permute(vector<int>& arr, int idx) {
    if (idx == arr.size()) {
        per.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        swap(arr[i], arr[idx]);
        permute(arr, idx + 1);
        swap(arr[i], arr[idx]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    permute(arr, 0);

    for (auto& v : per) {
        for (int& x : v) {
            cout << x << " ";
        }

        cout << endl;
    }
    
    return 0;
}