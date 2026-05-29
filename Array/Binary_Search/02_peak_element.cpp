#include <iostream>
#include <vector>
using namespace std;

int find_peak_element(vector<int>& arr) {
    int low = 0;
    int high = arr.size()-1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid + 1]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    vector<int> arr1 = {1,2,3,1};
    vector<int> arr2 = {1,2,1,3,5,6,4};

    cout << find_peak_element(arr1) << endl;
    cout << find_peak_element(arr2) << endl;
    return 0;
}