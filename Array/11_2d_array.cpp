#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter dimension for square matrix: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    
    cout << "Enter the values for " << n << " X " << n << " matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Your matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}