#include <iostream>
#include <vector>
using namespace std;

vector<int> min_prefix_array(vector<int> arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        arr[i] = min(arr[i], arr[i - 1]);
    }

    return arr;
}

int main() {
    vector<int> arr = {9, 4, 3, 5, 8, 7, 0};
    for (int x : min_prefix_array(arr)) {
        cout << x << " ";
    }
    
    cout << endl;
    return 0;
}