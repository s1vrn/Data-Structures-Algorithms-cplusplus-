/**
 * 📑 Suffix Array (Simple O(N log^2 N) Implementation)
 * 
 * A Suffix Array is a sorted array of all suffixes of a string.
 * It is a foundational structure for many advanced string problems.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Builds a suffix array in O(N log^2 N).
 * p[i] is the starting index of the i-th lexicographically smallest suffix.
 */
vector<int> build_suffix_array(string s) {
    s += "$"; // Add sentinel character
    int n = s.size();
    vector<int> p(n), c(n);
    
    // k = 0
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) p[i] = a[i].second;
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        c[p[i]] = (a[i].first == a[i - 1].first) ? c[p[i - 1]] : c[p[i - 1]] + 1;
    }

    // Iterative sorting of doubled lengths
    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++) p[i] = b[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            c[p[i]] = (b[i].first == b[i - 1].first) ? c[p[i - 1]] : c[p[i - 1]] + 1;
        }
        k++;
    }
    return p;
}

int main() {
    string s = "banana";
    vector<int> sa = build_suffix_array(s);

    cout << "Suffix Array for '" << s << "':" << endl;
    for (int i = 1; i < sa.size(); i++) { // Skip the '$' sentinel suffix
        cout << sa[i] << ": " << s.substr(sa[i]) << endl;
    }

    return 0;
}
