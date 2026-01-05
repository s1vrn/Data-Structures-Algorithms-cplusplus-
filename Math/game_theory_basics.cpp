/**
 * 🎮 Game Theory: Nim Game & Grundy Numbers
 * 
 * Most CP games are "Impartial Games" (moves depend only on state, not player).
 * The core concept is XOR-Sum (Nim-Sum).
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * Nim-Sum Theorem:
 * In a game of Nim with piles of sizes {x1, x2, ..., xn}, 
 * the first player has a winning strategy if and only if:
 * x1 ^ x2 ^ ... ^ xn != 0
 */

void solveNim(vector<int>& piles) {
    int nim_sum = 0;
    for (int x : piles) nim_sum ^= x;

    if (nim_sum != 0) {
        cout << "Result: First player wins!" << endl;
        
        // Finding a winning move:
        for (int i = 0; i < piles.size(); i++) {
            if ((piles[i] ^ nim_sum) < piles[i]) {
                cout << "Winning Move: Take from pile " << i 
                     << ", reducing size from " << piles[i] 
                     << " to " << (piles[i] ^ nim_sum) << endl;
                break;
            }
        }
    } else {
        cout << "Result: Second player wins (P-position)." << endl;
    }
}

int main() {
    vector<int> piles = {3, 4, 5};
    cout << "Game with piles {3, 4, 5}:" << endl;
    solveNim(piles);

    return 0;
}
