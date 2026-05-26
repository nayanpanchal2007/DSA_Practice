#include <iostream>
#include <vector>
using namespace std;

vector<int> counting_sort(vector<int>& arr) {
    int n = arr.size();

    int mx = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    vector<int> count(mx + 1);

    for (int x : arr) {
        count[x]++;
    }

    for (int i = 1; i <= mx; i++) {
        count[i] += count[i - 1];
    }

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    } 
    
    return ans;
}

int main() {
    vector<int> arr = {8, 8, 9, 4, 4, 1, 2, 1, 1, 3};

    vector<int> result = counting_sort(arr);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}