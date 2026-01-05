/**
 * 🏰 Manacher's Algorithm
 * 
 * Find the length of the longest palindromic substring centered at each position 
 * in O(N) time. Standard DP or Brute Force takes O(N^2).
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Manacher's algorithm finds the radius of the longest palindrome centered at each character.
 * To handle both even and odd length palindromes, we transform the string:
 * "aba" -> "#a#b#a#"
 */
vector<int> manacher(string s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    int n = t.size();
    vector<int> p(n, 0);
    int l = 0, r = -1;
    
    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && t[i - k] == t[i + k]) {
            k++;
        }
        p[i] = --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return p; // Radius of palindromes in the transformed string
}

int main() {
    string s = "abacaba";
    vector<int> p = manacher(s);

    int max_radius = 0;
    for (int r : p) max_radius = max(max_radius, r);

    cout << "String: " << s << endl;
    cout << "Longest Palindromic Substring Length: " << max_radius << endl;

    return 0;
}
