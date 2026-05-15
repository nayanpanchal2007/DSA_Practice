#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int second_largest(vector<int>& arr) {
    int n = arr.size();

    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    return second;
}

int main() {
    vector<int> arr = {5, 2, 8, 7};

    int second_large = second_largest(arr);

    cout << "Second largest = " << second_large << endl;
    return 0;
}