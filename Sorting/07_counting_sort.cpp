#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& arr) {
    int mx = *max_element(arr.begin(), arr.end());

    vector<int> freq(mx + 1, 0);

    for (int& x : arr) {
        freq[x]++;
    }

    int idx = 0;

    for (int i = 0; i <= mx; i++) {
        while (freq[i]--) {
            arr[idx] = i;
            idx++;
        }
    }
}

int main() {
    vector<int> arr = {5, 3, 2, 1, 4, 8, 7, 9, 6};

    counting_sort(arr);
    
    for (int& x : arr) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}