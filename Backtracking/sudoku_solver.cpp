/**
 * Sudoku Solver
 * 
 * Problem: Fill a 9x9 grid such that each row, column, and 3x3 box contains digits 1-9.
 * Approach: Backtracking.
 */

#include <iostream>
#include <vector>

using namespace std;

#define N 9

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

bool safe(int grid[N][N], int row, int col, int num) {
    // Check row
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;

    // Check col
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;

    // Check 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[N][N], int row, int col) {
    // Check if we have reached the 8th row and 9th col (0 indexed matrix)
    // we are returning true to avoid further backtracking
    if (row == N - 1 && col == N) return true;

    // Check if column value becomes 9 , we move to next row and
    // column start from 0
    if (col == N) {
        row++;
        col = 0;
    }

    // Check if the current position of the grid already contains value >0,
    // we iterate for next column
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (safe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

int main() {
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        cout << "no solution exists " << endl;

    return 0;
}
