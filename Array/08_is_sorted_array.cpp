#include <iostream>
#include <vector>
using namespace std;

bool is_sorted(vector<int> arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> arr = {1, 5, 21, 25};

    if (is_sorted(arr)) {
        cout << "Array is sorted.\n";
    } else {
        cout << "Array is not sorted.\n";
    }
    return 0;
}