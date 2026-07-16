#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_sum_array(vector<int> arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i] + arr[i - 1];
    }

    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    for (int x : prefix_sum_array(arr)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}