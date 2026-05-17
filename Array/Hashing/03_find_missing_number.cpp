#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int missing_number(vector<int> arr) {
    int n = arr.size() + 1;
    unordered_set<int> s(arr.begin(), arr.end());

    for (int i = 1; i <= n; i++) {
        if (s.count(i) == 0) {
            return i;
        }
    }

    return  -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 5, 6, 7, 8, 9};
    int missing = missing_number(arr);

    cout << "Missing number is: " << missing << endl;
    return 0;
}