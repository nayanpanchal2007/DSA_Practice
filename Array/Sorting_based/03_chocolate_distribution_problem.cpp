#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int distribute_chocolates(vector<int> arr, int m) {
    if (arr.size() == 0 || m == 0) {
        return 0;
    }

    if (m > arr.size()) {
        return -1;
    }

    sort(arr.begin(), arr.end());

    int min_diff = INT_MAX;
    
    for (int i = 0; i + m - 1 < arr.size(); i++) {
        int diff = arr[i + m - 1] - arr[i];
        min_diff = min(diff, min_diff);
    }

    return min_diff;
}

int main() {
    vector<int> arr = {1, 3, 4, 9, 9, 12};
    int m = 2;

    cout << "Minimum difference = " << distribute_chocolates(arr, m) << endl;
    return 0;
}