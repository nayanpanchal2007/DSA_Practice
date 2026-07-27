#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sum_of_distinct_elements(vector<int> arr) {
    unordered_set<int> s(begin(arr), end(arr));
    int sum = 0;
    
    for (int x : s) {
        sum += x;
    }

    return sum;
}

int main() {
    cout << sum_of_distinct_elements({1, 2, 3, 4, 5, 5}) << endl;
    cout << sum_of_distinct_elements({1, 1, 1, 1, 1}) << endl;
    cout << sum_of_distinct_elements({1, 2, 3, 2}) << endl;
    return 0;
}