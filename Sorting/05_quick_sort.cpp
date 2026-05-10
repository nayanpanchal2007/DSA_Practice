#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int idx = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[++idx], arr[j]);
        }
    }

    swap(arr[right], arr[++idx]);
    return idx;
}

void quick_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quick_sort(arr, left, pi - 1);
        quick_sort(arr, pi + 1, right);
    }
}

int main() {
    vector<int> arr = {5, 6, 2, 3, 1, 4};

    quick_sort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}