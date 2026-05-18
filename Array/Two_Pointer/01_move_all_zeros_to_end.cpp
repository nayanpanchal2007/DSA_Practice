#include <iostream>
#include <vector>
using namespace std;

void move_zeros_to_end(vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

int main() {
    vector<int> arr = {2, 1, 0, 3, 0, 0, 0, 9, 8, 0, 3};

    move_zeros_to_end(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}