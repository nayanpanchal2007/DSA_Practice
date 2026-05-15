#include <iostream>
#include <vector>
using namespace std;

pair<int, int> min_max(vector<int>& arr) {
    int n = arr.size();
    int min = arr[0];
    int max = arr[0];

    pair<int, int> ans;

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }

        if (arr[i] > max) {
            max = arr[i];
        }
    }

    ans.first = min;
    ans.second = max;
    
    return ans;
}

int main() {
    vector<int> arr = {8, 2, 6, 1, 9, 3, 5, 10, 4, 7};

    pair<int, int> ans = min_max(arr);
    
    cout << "Min = " << ans.first << endl;
    cout << "Max = " << ans.second << endl;
    
    return 0;
}