#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void generate_subsets(vector<int>& arr, vector<int>& curr, int idx) {
    if (idx == arr.size()) {
        ans.push_back(curr);
        return;
    }

    curr.push_back(arr[idx]);
    generate_subsets(arr, curr, idx + 1);
    curr.pop_back();

    generate_subsets(arr, curr, idx + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> curr;
    
    generate_subsets(arr, curr, 0);

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].empty()) {
            cout << "{}";
        } else {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }

            cout << endl;
        }
    }
    
    return 0;
}