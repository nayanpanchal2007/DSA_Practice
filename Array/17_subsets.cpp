#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;

void generate_subsets(vector<int>& arr, int index, vector<int>& curr) {
    int n = arr.size();

    if (index == n) {
        subsets.push_back(curr);
        return;
    }

    generate_subsets(arr, index + 1, curr);
    curr.push_back(arr[index]);
    
    generate_subsets(arr, index + 1, curr);
    curr.pop_back();
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> curr;

    generate_subsets(arr, 0, curr);
    
    for (auto& v : subsets) {
        for (int& x : v) {
            cout << x << " ";
        }

        cout << endl;
    }
    return 0;
}