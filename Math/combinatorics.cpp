/**
 * 🎲 Combinatorics (nCr and nPr)
 * 
 * Efficiently calculating combinations and permutations for large n.
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1000005;

ll fact[MAXN], invFact[MAXN];

ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

// Precompute factorials and their modular inverses in O(N)
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

// nCr = n! / (r! * (n-r)!) % MOD
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

// nPr = n! / (n-r)! % MOD
ll nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (fact[n] * invFact[n - r]) % MOD;
}

int main() {
    precompute();

    int n = 10, r = 3;
    cout << "10C3: " << nCr(n, r) << endl; // 10*9*8 / (3*2*1) = 120
    cout << "10P3: " << nPr(n, r) << endl; // 10*9*8 = 720

    return 0;
}
