#include <bits/stdc++.h>
using namespace std;

bool is_valid(vector<vector<char>>& board, int row, int col, char ch) {
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == ch) {
            return false;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (board[i][col] == ch) {
            return false;
        }
    }

    int r = (row / 3) * 3;
    int c = (col / 3) * 3;

    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            if (board[i][j] == ch) {
                return false;
            }
        }
    }

    return true;
}

bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (is_valid(board, i, j, ch)) {
                        board[i][j] = ch;
                        if (solve(board)) return true;
                        board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }
    
    return true;
}

void print_board(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        if (i == 3 || i == 6) {
            cout << "------|-------|-------" << endl;
        }
        
        for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6) {
                cout << " | ";
            }
            
            cout << board[i][j];

            if (j != 2 && j != 5) {
                cout << " ";
            }
        }

        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'.', '.', '.', '.', '.', '7', '.', '.', '.'},
        {'.', '.', '5', '4', '.', '.', '1', '.', '8'},
        {'9', '.', '.', '6', '.', '.', '5', '.', '2'},
        {'.', '1', '.', '.', '.', '.', '9', '.', '3'},
        {'.', '.', '.', '.', '2', '.', '.', '.', '.'},
        {'2', '.', '6', '.', '.', '.', '.', '4', '.'},
        {'3', '.', '7', '.', '.', '9', '.', '.', '1'},
        {'8', '.', '4', '.', '.', '1', '3', '.', '.'},
        {'.', '.', '.', '2', '.', '.', '.', '.', '.'}
    };

    solve(board);
    print_board(board);    

    return 0;
}