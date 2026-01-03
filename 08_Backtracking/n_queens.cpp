/**
 * N-Queens Problem
 * 
 * Problem: Place N queens on an NxN chessboard such that no two queens attack each other.
 * Approach: Backtracking.
 */

#include <iostream>
#include <vector>

using namespace std;

int N;

// Check if a queen can be placed at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive Backtracking Function
bool solveNQUtil(vector<vector<int>>& board, int col) {
    // Base case: If all queens are placed then return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove queen from board[i][col] (Backtrack)
            board[i][col] = 0;
        }
    }

    // If the queen can not be placed in any row in this column col
    // then return false
    return false;
}

void printSolution(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << "\n";
    }
}

int main() {
    cout << "Enter size of board (N): \n";
    // N = 4; // Simulated Input
    // cin >> N;
    N = 8; // Standard chessboard

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist\n";
    } else {
        printSolution(board);
    }

    return 0;
}
