#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> get_duplicates(vector<int> arr) {
    unordered_set<int> s;
    unordered_set<int> dups;

    for (int x : arr) {        
        if (s.find(x) != s.end()) {
            dups.insert(x);
        } else {
            s.insert(x);
        }
    }

    return vector<int>(dups.begin(), dups.end());
}

int main() {
    vector<int> arr = {3, 2, 1, 1, 2, 2, 2, 4, 5, 5};
    vector<int> duplicates = get_duplicates(arr);

    cout << "Duplicates: ";
    for (int x : duplicates) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}