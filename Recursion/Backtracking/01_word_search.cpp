#include <bits/stdc++.h>
using namespace std;

bool found(vector<vector<char>>& board, int i, int j, string& word, int idx) {
    if (idx == word.length()) {
        return true;
    }

    int m = board.size();
    int n = board[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#' || board[i][j] != word[idx]) {
        return false;
    }

    int temp = board[i][j];
    board[i][j] = '#';

    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, 1, 0, -1};

    for (int d = 0; d < 4; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];

        if (found(board, ni, nj, word, idx + 1)) {
            return true;
        }
    }

    board[i][j] = temp;

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                if (found(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'L', 'F', 'B', 'G', 'H'},
        {'O', 'A', 'N', 'P', 'G'},
        {'A', 'F', 'A', 'N', 'Q'},
        {'D', 'B', 'S', 'C', 'N'}
    };
    string word = "LOANAN";
    
    if (exist(board, word)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}