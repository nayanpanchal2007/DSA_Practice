#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> count_frequency(vector<int>& arr) {
    unordered_map<int, int> mp;

    for (int x : arr) {
        mp[x]++;
    }

    return mp;
}

int main() {
    vector<int> arr = {3, 2, 1, 1, 3, 3, 3, 4, 5, 5};

    unordered_map<int, int> m = count_frequency(arr);

    cout << "Element = Frequency" << endl;
    for (const auto& p : m) {
        cout << p.first << " = " << p.second << endl;
    }
    
    return 0;
}