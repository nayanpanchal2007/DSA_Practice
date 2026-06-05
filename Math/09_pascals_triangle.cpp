#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pascal_triangle(int n) {
    vector<vector<int>> ans;

    for (int i = 0; i < n; ++i) {
        vector<int> row(i+1, 1);

        for (int j = 1; j < i; ++j) {
            row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }

        ans.push_back(row);
    }
    
    return ans;
}

int main() {
    vector<vector<int>> pas = pascal_triangle(5);
    int n = pas.size();
    for (int i = 0; i < n; i++) {
        int m = pas[i].size();
        
        for (int j = 0; j < m; j++) {
            cout << pas[i][j] << " ";
        }

        cout << endl;
    }
    
    return 0;
}