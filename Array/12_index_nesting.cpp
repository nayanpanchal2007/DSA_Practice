#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Index nesting:-
 * ans[i] = arr[arr[i]]
 */

vector<int> index_nesting_array(vector<int>& arr) {
    vector<int> ans;

    for (int x : arr) {
        ans.push_back(arr[x]);
    }

    return ans;
}

int main() {
    vector<int> arr = {0, 2, 3, 1, 4, 6, 5};

    vector<int> result = index_nesting_array(arr);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}