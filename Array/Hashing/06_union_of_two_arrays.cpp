#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> union_of_arrays(vector<int>& a, vector<int>& b) {
    unordered_set<int> s(a.begin(), a.end());
    s.insert(b.begin(), b.end());

    return vector<int>(s.begin(), s.end());
}

int main() {
    vector<int> a = {1, 2, 3, 5};
    vector<int> b = {2, 1, 9, 8, 67};

    for (int x : union_of_arrays(a, b)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}