#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sum_of_unique_elements(vector<int> arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    int sum = 0;

    for (int x : s) {
        sum += x;
    }

    return sum;
}

int main() {
    cout << sum_of_unique_elements({1, 2, 2, 3, 4, 4, 4}) << endl;
    cout << sum_of_unique_elements({3, 2, 8, 3, 3}) << endl;
    cout << sum_of_unique_elements({9, 9, 9, 9}) << endl;
    cout << sum_of_unique_elements({-1, -1, 2, -1}) << endl;
    return 0;
}