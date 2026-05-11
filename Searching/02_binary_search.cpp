#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {0, 1, 3, 5, 7, 9, 10};
    int target = 9;

    cout << search(arr, target) << endl;
    return 0;
}