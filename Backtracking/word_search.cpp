/**
 * 🔍 Word Search (Grid Backtracking)
 * 
 * Problem: Given an MxN grid of characters and a string 'word', 
 * return true if 'word' exists in the grid.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool backtrack(vector<vector<char>>& board, string& word, int idx, int r, int c) {
    if (idx == word.length()) return true; // Found the word
    
    int R = board.size();
    int C = board[0].size();

    // Out of bounds or character doesn't match
    if (r < 0 || r >= R || c < 0 || c >= C || board[r][c] != word[idx]) {
        return false;
    }

    char temp = board[r][c];
    board[r][c] = '#'; // Mark as visited for this recursive path

    // Search in all 4 directions
    bool found = backtrack(board, word, idx + 1, r + 1, c) ||
                 backtrack(board, word, idx + 1, r - 1, c) ||
                 backtrack(board, word, idx + 1, r, c + 1) ||
                 backtrack(board, word, idx + 1, r, c - 1);

    board[r][c] = temp; // Unmark (Backtrack)
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (backtrack(board, word, 0, i, j)) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";
    if (exist(board, word)) cout << "Word '" << word << "' found!" << endl;
    else cout << "Word '" << word << "' NOT found." << endl;

    return 0;
}
