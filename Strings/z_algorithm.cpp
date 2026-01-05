/**
 * ⚡ Z-Algorithm
 * 
 * The Z-array for a string S is an array where Z[i] is the length of the longest 
 * common prefix between S and the suffix of S starting at i.
 * Time Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

/**
 * Z-algorithm is often used for pattern matching by creating a string:
 * pattern + "$" + text
 */
void search(string text, string pattern) {
    string combined = pattern + "$" + text;
    vector<int> z = z_function(combined);
    int p_len = pattern.length();
    
    cout << "Pattern '" << pattern << "' found at indices: ";
    for (int i = 0; i < z.size(); i++) {
        if (z[i] == p_len) {
            cout << i - p_len - 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    string text = "azbazbazbaz";
    string pattern = "baz";
    
    search(text, pattern);

    return 0;
}
