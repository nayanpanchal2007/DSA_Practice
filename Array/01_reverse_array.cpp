#include <iostream>
#include <vector>
using namespace std;

// Two pointer approach
void reverse(vector<int>& arr) {
    int left = 0;
    int right = arr.size()-1;

    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    
    reverse(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}