#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNBishops(vector<vector<int>>& board, int row, int col, int placed, int n) {
    if (placed == n)
        return true;

    if (row == n)
        return false;

    if (col == n)
        return solveNBishops(board, row + 1, 0, placed, n);

    if (isSafe(board, row, col, n)) {
        board[row][col] = 1;

        if (solveNBishops(board, row, col + 1, placed + 1, n))
            return true;

        board[row][col] = 0;
    }

    return solveNBishops(board, row, col + 1, placed, n);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNBishops(board, 0, 0, 0, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] ? "B " : ". ");
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
