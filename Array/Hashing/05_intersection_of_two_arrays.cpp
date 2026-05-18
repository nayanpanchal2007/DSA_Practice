#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
    unordered_set<int> s(a.begin(), a.end());
    vector<int> ans;

    for (int x : b) {
        if (s.find(x) != s.end()) {
            ans.push_back(x);
            s.erase(x);
        }
    }

    return ans;
}

int main() {
    vector<int> a = {2, 1, 5, 7, 8, 10};
    vector<int> b = {5, 7, 3, 8, 9};

    for (int x : intersection(a, b)) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}