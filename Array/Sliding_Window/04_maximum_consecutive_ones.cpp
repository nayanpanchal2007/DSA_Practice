#include <iostream>
#include <vector>
using namespace std;

int max_consecutive_ones(vector<int>& arr) {
    int count = 0;
    int max_count = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            count++;
            max_count = max(max_count, count);
        } else {
            count = 0;
        }
    }

    return max_count;
}

int main() {
    vector<int> arr = {1, 1, 0, 1, 1, 1, 1};
    cout << "Max consecutive ones = " << max_consecutive_ones(arr) << endl;
    return 0;
}