#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board,
            int row, int col, int n) {

    // Check same column above
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

bool solve(vector<string>& board,
           int row, int n) {

    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';

            if (solve(board, row + 1, n))
                return true;

            // Backtrack
            board[row][col] = '.';
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> board(n, string(n, '.'));

    if (solve(board, 0, n)) {
        for (int i = 0; i < n; i++) {
            cout << board[i] << endl;
        }
    } else {
        cout << "No solution exists";
    }

    return 0;
}