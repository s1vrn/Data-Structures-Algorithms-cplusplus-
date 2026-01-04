/**
 * 🏆 Ultimate Competitive Programming Template
 * 
 * This template is designed to be fast, clear, and modular.
 * It includes the most common utilities used by top competitors.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// --- 1. Macros & Type Definitions ---
// Short names for long types save time and reduce typos.
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Use 'using' (Modern C++) instead of typedef if preferred:
// using ll = long long;

// --- 2. Constants ---
// Good practice to define common values here.
const int INF = 1e9 + 7;
const ll LINF = 1e18;

// --- 3. The Solve Function ---
// We put the logic here so we can easily run it multiple times for test cases.
void solve() {
    int n;
    if (!(cin >> n)) return;

    // Your logic goes here
    cout << "Processing: " << n << "\n";
}

// --- 4. Main Function ---
int main() {
    // Speed up input and output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Multi-test case support
    int t = 1;
    // cin >> t; // Only uncomment if problem says "T test cases follow"
    
    while(t--) {
        solve();
    }

    return 0;
}
