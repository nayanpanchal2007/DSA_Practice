#include <iostream>
#include <vector>
using namespace std;

int max_sum_subarray(vector<int>& arr, int k) {
    int n = arr.size();

    if (n < k || k <= 0) {
        return 0;
    }

    int curr_sum = 0;
    int max_sum;

    for (int i = 0; i < k; i++) {
        curr_sum += arr[i];
    }

    max_sum = curr_sum;

    for (int i = k; i < n; i++) {
        curr_sum = curr_sum - arr[i - k] + arr[i];
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

    return max_sum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    cout << "Maximum sum of subarrays = " << max_sum_subarray(arr, k) << endl;
    return 0;
}