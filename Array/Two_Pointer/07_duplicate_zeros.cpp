#include <bits/stdc++.h>
using namespace std;

void duplicate_zeros(vector<int>& arr) {
    int n = arr.size();
    int zeros = count(arr.begin(), arr.end(), 0);
    int i = n - 1;
    int j = n + zeros - 1;

    while (i >= 0) {
        if (j < n) arr[j] = arr[i];
        if (arr[i] == 0) {
            j--;
            if (j < n) arr[j] = 0;
        }
        i--;
        j--;
    }
    
}

int main() {
    vector<int> arr = {1,0,2,3,0,4,5,0};
    duplicate_zeros(arr);

    for (int& x : arr) {
        cout << x << " ";
    }
    cout << endl;
    
    vector<int> arr2 = {1,2,3};
    duplicate_zeros(arr2);

    for (int& x : arr2) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}