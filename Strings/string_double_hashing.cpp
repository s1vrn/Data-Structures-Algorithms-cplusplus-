/**
 * 🔗 String Double Hashing
 * 
 * Hashing strings allows for O(1) comparison after O(N) preprocessing. 
 * Using two different bases and mods significantly reduces collision probability.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll BASE1 = 31;
const ll BASE2 = 37;

struct Hash {
    vector<ll> h1, h2, p1, p2;

    Hash(string s) {
        int n = s.size();
        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        p1.resize(n + 1, 1);
        p2.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + (s[i] - 'a' + 1)) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + (s[i] - 'a' + 1)) % MOD2;
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }
    }

    // Get 0-indexed hash of substring [l, r]
    pair<ll, ll> get_hash(int l, int r) {
        ll res1 = (h1[r + 1] - h1[l] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
        ll res2 = (h2[r + 1] - h2[l] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
        return {res1, res2};
    }
};

int main() {
    string s = "berlinberlin";
    Hash h(s);

    auto hash1 = h.get_hash(0, 5); // "berlin"
    auto hash2 = h.get_hash(6, 11); // "berlin"

    if (hash1 == hash2) {
        cout << "Hashes match! The substrings are equal." << endl;
    } else {
        cout << "Hashes don't match." << endl;
    }

    return 0;
}
