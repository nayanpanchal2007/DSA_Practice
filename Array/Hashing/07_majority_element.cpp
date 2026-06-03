#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int majority_element(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> mp;

    for (int x : arr) {
        mp[x]++;
    }

    for (int x : arr) {
        if (mp[x] > n / 2) {
            return x;
        }
    }

    return -1;
}

int main() {
    vector<int> arr1 = {3,2,3};
    vector<int> arr2 = {2,2,1,1,1,2,2};

    cout << majority_element(arr1) << endl;
    cout << majority_element(arr2) << endl;
    return 0;
}