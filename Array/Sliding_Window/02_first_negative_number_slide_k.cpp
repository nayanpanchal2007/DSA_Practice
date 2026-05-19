#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> first_negative_in_window_k(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    if (!dq.empty()) {
        ans.push_back(arr[dq.front()]);
    } else {
        ans.push_back(0);
    }

    for (int i = k; i < n; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }

        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    for (int x : first_negative_in_window_k(arr, k)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}