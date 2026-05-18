#include <iostream>
#include <vector>
using namespace std;

vector<int> remove_duplicates(vector<int>& arr) {
    int n = arr.size();

    if (n == 0) {
        return {};
    }

    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    return vector<int>(arr.begin(), arr.begin()+j+1);
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 4, 4};

    for (int x : remove_duplicates(arr)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}