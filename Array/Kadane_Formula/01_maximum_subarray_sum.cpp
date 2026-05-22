#include <iostream>
#include <vector>
using namespace std;

int maximum_subarray_sum(vector<int>& arr) {
    int curr_sum = 0;
    int max_sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        curr_sum = max(arr[i], curr_sum + arr[i]);
        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

int main() {
    vector<int> arr = {2, 3, -1, 9, 10, -3, -5};

    cout << "Maximum subarray sum = " << maximum_subarray_sum(arr) << endl;
    return 0;
}