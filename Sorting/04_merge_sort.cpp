#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> l(n1);
    vector<int> r(n2);

    for (int i = 0; i < n1; i++) {
        l[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        r[j] = arr[j + mid + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[k++] = l[i++];
        } else {
            arr[k++] = r[j++];
        }
    }

    while (i < n1) {
        arr[k++] = l[i++];
    }

    while (j < n2) {
        arr[k++] = r[j++];
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {5, 6, 2, 3, 1, 4};

    merge_sort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}