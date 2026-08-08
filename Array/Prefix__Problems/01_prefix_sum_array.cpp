#include <iostream>
#include <vector>
using namespace std;

void print_arr(vector<int> arr) {
    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;
}

vector<int> prefix_sum(vector<int> arr) {
    int n = arr.size();
    vector<int> pref = arr;

    for (int i = 1; i < n; i++) {
        pref[i] += pref[i - 1];
    }

    return pref;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {8, 3, 2, 9, -1, 2, -3};
    vector<int> arr3 = {-9, 8, 3, 2, -1, 0};
    vector<int> arr4 = {6, 3, 2};
    vector<int> arr5 = {-5};

    print_arr(prefix_sum(arr1));
    print_arr(prefix_sum(arr2));
    print_arr(prefix_sum(arr3));
    print_arr(prefix_sum(arr4));
    print_arr(prefix_sum(arr5));
    return 0;
}