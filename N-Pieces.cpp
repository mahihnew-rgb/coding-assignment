#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n, int type) {

    
    if (type == 1 || type == 4) {
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 1)
                return false;
        }
    }

    
    if (type == 1 || type == 4) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1)
                return false;
        }
    }

    
    if (type == 1 || type == 3) {
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1)
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 1)
                return false;
        }
    }

    
    if (type == 2) {
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
    }

    return true;
}

bool solve(vector<vector<int>>& board, int row, int col,
           int placed, int n, int type) {

    if (placed == n)
        return true;

    if (row == n)
        return false;

    if (col == n)
        return solve(board, row + 1, 0, placed, n, type);

    if (isSafe(board, row, col, n, type)) {
        board[row][col] = 1;

        if (solve(board, row, col + 1, placed + 1, n, type))
            return true;

        board[row][col] = 0;
    }

    return solve(board, row, col + 1, placed, n, type);
}

int main() {
    int n, type;
    cin >> n >> type;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solve(board, 0, 0, 0, n, type)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] ? "P " : ". ");
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
