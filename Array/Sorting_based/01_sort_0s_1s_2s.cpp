#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void sort(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 0, 1, 1, 0, 0, 2};

    sort(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}