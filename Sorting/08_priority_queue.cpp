#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sorting(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : arr) {
        pq.push(x);
    }

    for (int& x : arr) {
        x = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> arr = {2, 8, 7, 5, 1, 3, 6};

    sorting(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;   
}