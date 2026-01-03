/**
 * Generating Permutations
 * 
 * Problem: Generate all permutations of a string or array.
 * Approach: Backtracking (or using std::next_permutation).
 * Complexity: O(N * N!)
 */

#include <iostream>
#include <string>
#include <algorithm> // For std::next_permutation (The easy way)
#include <vector>

using namespace std;

// Backtracking Approach
void customPermutations(string& s, int l, int r) {
    // Base case
    if (l == r)
        cout << s << "\n";
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {
            // Swapping done
            swap(s[l], s[i]);

            // Recursion called
            customPermutations(s, l + 1, r);

            // Backtrack
            swap(s[l], s[i]);
        }
    }
}

int main() {
    string s = "ABC";
    int n = s.size();
    
    cout << "--- Backtracking Permutations ---\n";
    customPermutations(s, 0, n - 1);

    cout << "\n--- STL next_permutation ---\n";
    string s2 = "123";
    // Sort first to ensure order
    sort(s2.begin(), s2.end());
    do {
        cout << s2 << "\n";
    } while (next_permutation(s2.begin(), s2.end()));

    return 0;
}
