/**
 * @details Sort by parity means that the even numbers comes first and odd numbers comes at last 
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sort_by_parity(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        if (arr[left] % 2 == 0) {
            left++;
        } else if (arr[right] % 2 != 0) {
            right--;
        } else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    vector<int> arr = {3, 4, 2, 1, 8, 9, 5, 6, 10};
    sort_by_parity(arr);

    for (int& x : arr) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}