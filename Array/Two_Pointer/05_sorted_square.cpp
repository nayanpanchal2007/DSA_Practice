#include <iostream>
#include <vector>
using namespace std;

vector<int> sorted_square(const vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    
    int left = 0;
    int right = n - 1;
    int j = n - 1;

    while (left <= right) {
        if (abs(arr[left]) >= abs(arr[right])) {
            ans[j] = arr[left] * arr[left];
            left++;
        } else {
            ans[j] = arr[right] * arr[right];
            right--;
        }

        j--;
    }

    return ans;
}

int main() {
    vector<int> arr = {-3, -2, 1, 0, 4};

    for (int x : sorted_square(arr)) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}