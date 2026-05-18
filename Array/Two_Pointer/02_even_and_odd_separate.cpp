#include <iostream>
#include <vector>
using namespace std;

void separate_even_odd(vector<int>& arr) {
    int left = 0;
    int right = arr.size()-1;

    while (left < right) {
        while (arr[left] % 2 == 0 && left < right) {
            left++;
        }

        while (arr[right] % 2 != 0 && left < right) {
            right--;
        }

        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    vector<int> arr = {1,2,3,4,5,6};

    separate_even_odd(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}