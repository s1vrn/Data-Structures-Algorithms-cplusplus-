/**
 * Knuth-Morris-Pratt (KMP) Algorithm
 * 
 * Problem: Find occurrences of a pattern P in a text T.
 * Naive Approach: O(N * M).
 * KMP Approach: O(N + M) using a prefix function (LPS array).
 * 
 * LPS[i] = Longest Proper Prefix which is also a Suffix for pattern[0...i].
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Compute LPS Array
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m);
    int len = 0; // Length of previous longest prefix suffix
    lps[0] = 0; // Always 0
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Fallback to previous prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP Search
void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << "\n";
            j = lps[j - 1]; // Look for next match
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    cout << "Text: " << text << "\n";
    cout << "Pattern: " << pattern << "\n";
    KMPSearch(text, pattern);
    
    return 0;
}
