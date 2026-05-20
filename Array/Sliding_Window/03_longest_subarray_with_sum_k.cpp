#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longest_subarray_with_sum_k(vector<int>& arr, int sum_k) {
    int n = arr.size();

    unordered_map<int, int> mp;
    int prefix_sum = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if (prefix_sum == sum_k) {
            max_len = i + 1;
        }

        if (mp.find(prefix_sum - sum_k) != mp.end()) {
            int len = i - mp[prefix_sum - sum_k];
            max_len = max(max_len, len);
        }

        if (mp.find(prefix_sum) == mp.end()) {
            mp[prefix_sum] = i;
        }
    }

    return max_len;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int sum_k = 6;

    cout << "Max length = " << longest_subarray_with_sum_k(arr, sum_k) << endl;    
    return 0;
}