#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sorted_arrays(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> c(n1 + n2);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            k++;
            i++;
        } else {
            c[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n1) {
        c[k] = a[i];
        k++;
        i++;
    }

    while (j < n2) {
        c[k] = b[j];
        k++;
        j++;
    }

    return c;
}

int main() {
    vector<int> a = {1, 3, 5, 9};
    vector<int> b = {2, 4, 8, 10};

    vector<int> arr = merge_sorted_arrays(a, b);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}