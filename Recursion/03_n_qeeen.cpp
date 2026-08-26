#include <iostream>
#include <vector>
using namespace std;

bool is_valid(vector<string>& board, int n, int row, int col) {
    // Upper column
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void solve(vector<vector<string>>& ans, vector<string>& board, int n, int row) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (is_valid(board, n, row, col)) {
            board[row][col] = 'Q';
            solve(ans, board, n, row + 1);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 5;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    solve(ans, board, n, 0);
    int i = 0;

    for (auto& vs : ans) {
        cout << "\nSolution " << i + 1 << ":" << endl;
        
        for (string& s : vs) {
            for (char& ch : s) {
                cout << ch << "  ";
            }

            cout << endl;
        }

        i++;
        cout << endl;
    }

    return 0;
}
