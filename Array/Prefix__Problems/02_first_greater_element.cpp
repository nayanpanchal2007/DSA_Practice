#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> first_greater_element(vector<int>& arr) {
    int n = arr.size();
    vector<int> great(n, -1);

    for (int i = 0; i < n; i++) {
        int j = i + 1;

        while (j < n) {
            if (arr[j] > arr[i]) {
                great[i] = arr[j];
                break;
            }
            
            j++;
        }
    }

    return great;
}

int main() {
    vector<int> arr = {3, 8, 5, 4, 6, 1, 2};

    for (int& x : first_greater_element(arr)) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}