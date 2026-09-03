#include <bits/stdc++.h>
using namespace std;

int search_in_rotated_sorted_array(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[left] <= arr[mid]) {
            if (arr[left] <= target && target <= arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (arr[mid] <= target && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    cout << "10 at position: " << search_in_rotated_sorted_array(arr, 10) << endl;
    cout << "8 at position: " << search_in_rotated_sorted_array(arr, 8) << endl;
    cout << "5 at position: " << search_in_rotated_sorted_array(arr, 5) << endl;
    cout << "7 at position: " << search_in_rotated_sorted_array(arr, 7) << endl;
    cout << "2 at position: " << search_in_rotated_sorted_array(arr, 2) << endl;
    return 0;
}