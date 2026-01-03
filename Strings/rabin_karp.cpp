/**
 * Rabin-Karp Algorithm
 * 
 * Uses Rolling Hash to find patterns.
 * Best Case: O(N+M), Worst Case: O(N*M) (Hash collisions).
 * 
 * Hash Function: (c1 * p^0 + c2 * p^1 + ... ) % MOD
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int d = 256; // Number of characters in input alphabet
const int q = 101; // A prime number

void search(string pattern, string text) {
    int M = pattern.length();
    int N = text.length();
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text and pattern
        if (p == t) {
            // Check for characters one by one
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
                cout << "Pattern found at index " << i << "\n";
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;

            // We might get negative value of t, converting it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    
    cout << "Text: " << text << "\n";
    cout << "Pattern: " << pattern << "\n";
    search(pattern, text);
    
    return 0;
}
