#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {3, 9, 2, 1, 0, 5};
    int target = 0;
    cout << search(arr, target) << endl;
    return 0;
}