#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    int moves[8][2] = {
        {-2, -1}, {-2, 1},
        {-1, -2}, {-1, 2},
        {1, -2}, {1, 2},
        {2, -1}, {2, 1}
    };

    for (auto& move : moves) {
        int r = row + move[0];
        int c = col + move[1];

        if (r >= 0 && r < n && c >= 0 && c < n && board[r][c] == 1)
            return false;
    }

    return true;
}

bool solveNKnights(vector<vector<int>>& board, int row, int col, int placed, int n) {
    if (placed == n)
        return true;

    if (row == n)
        return false;

    if (col == n)
        return solveNKnights(board, row + 1, 0, placed, n);

    if (isSafe(board, row, col, n)) {
        board[row][col] = 1;

        if (solveNKnights(board, row, col + 1, placed + 1, n))
            return true;

        board[row][col] = 0;
    }

    return solveNKnights(board, row, col + 1, placed, n);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNKnights(board, 0, 0, 0, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] ? "K " : ". ");
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
