#include <iostream>
#include <vector>
using namespace std;

void rotate_right(vector<int>& arr) {
    int n = arr.size();
    int temp = arr[n - 1];

    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = temp;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    rotate_right(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}