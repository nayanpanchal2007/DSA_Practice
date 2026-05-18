#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> get_unique_elements(vector<int>& arr) {
    unordered_map<int, int> freq;

    for (int x : arr) {
        freq[x]++;
    }

    vector<int> ans;

    for (int x : arr) {
        if (freq[x] == 1) {
            ans.push_back(x);
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 1, 5, 7, 9};
    vector<int> unique = get_unique_elements(arr);

    for (int u : unique) {
        cout << u << " ";
    }
    cout << endl; 

    return 0;
}