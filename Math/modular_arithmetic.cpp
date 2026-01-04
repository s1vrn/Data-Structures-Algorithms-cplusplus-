/**
 * 🔢 Modular Arithmetic
 * 
 * In Competitive Programming, many problems ask for answers "modulo 10^9 + 7".
 * This is to prevent integer overflow and focus on the logic.
 */

#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// 1. Basic Modular Properties:
// (a + b) % M = ((a % M) + (b % M)) % M
// (a - b) % M = ((a % M) - (b % M) + M) % M  // Note the extra + M for negative results
// (a * b) % M = ((a % M) * (b % M)) % M

// 2. Binary Exponentiation (a^b % MOD) - O(log b)
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

// 3. Modular Multiplicative Inverse (a^-1 % MOD)
// Only exists if gcd(a, MOD) = 1. If MOD is prime, use Fermat's Little Theorem:
// a^(MOD-2) % MOD
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

// 4. Modular Division (a / b % MOD)
// (a / b) % MOD = (a * b^-1) % MOD
ll modDivide(ll a, ll b) {
    return (a % MOD * modInverse(b)) % MOD;
}

int main() {
    ll a = 123456789;
    ll b = 987654321;

    cout << "Addition: " << (a + b) % MOD << endl;
    cout << "Subtraction: " << (a - b + MOD) % MOD << endl;
    cout << "Multiplication: " << (a * b) % MOD << endl;
    cout << "Division (a/b): " << modDivide(a, b) << endl;
    
    cout << "Power (2^10): " << power(2, 10) << endl;

    return 0;
}
