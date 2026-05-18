#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();

    vector<int> arr(n1 + n2);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }

    while (i < n1) {
        arr[k++] = a[i++];
    }

    while (j < n2) {
        arr[k++] = b[j++];
    }

    return arr;
}

int main() {
    vector<int> a = {1, 2, 3, 5};
    vector<int> b = {4, 5, 8, 9, 10, 11, 12};

    vector<int> arr = merge(a, b);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}