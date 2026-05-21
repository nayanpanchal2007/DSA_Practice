#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int min_subarray_len(vector<int>& arr, int target) {
    int n = arr.size();

    int left = 0;
    int sum = 0;

    int min_len = INT_MAX;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum >= target) {
            min_len = min(min_len, right - left + 1);

            sum -= arr[left];
            left++; 
        }
    }

    if (min_len == INT_MAX) {
        return 0;
    }
    return min_len;
}

int main() {
    vector<int> arr = {1, 2, 4, 2, 5};
    int target = 7;

    cout << "Minimum size of subarray : " << min_subarray_len(arr, target);
    return 0;
}