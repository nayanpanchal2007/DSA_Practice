#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr1 = {2, 3, 4, 5, 7};
    int target1 = 5;

    vector<int> arr2 = {9, 94, 103, 299};
    int target2 = 299;

    vector<int> arr3 = {3, 9, 12, 89, 90, 93, 98, 100};
    int target3 = 9;

    vector<int> arr4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target4 = 0;

    cout << binary_search(arr1, target1) << endl;
    cout << binary_search(arr2, target2) << endl;
    cout << binary_search(arr3, target3) << endl;
    cout << binary_search(arr4, target4) << endl;
    return 0;
}