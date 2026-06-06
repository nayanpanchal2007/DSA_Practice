#include <iostream>
using namespace std;

int remove_element(int arr[], int n, int rm) {
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != rm) {
            arr[k++] = arr[i];
        }
    }

    return k;
}

int main() {
    int arr[] = {1,2,3,5,5,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int rm = 5;

    int new_size = remove_element(arr, n, rm);
    
    for (int i = 0; i < new_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}