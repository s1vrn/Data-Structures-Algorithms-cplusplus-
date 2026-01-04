/**
 * 🏭 Advanced Sieve: Linear Sieve & SPF
 * 
 * Standard Sieve of Eratosthenes is O(N log log N). 
 * Linear Sieve is O(N) and also gives us the Smallest Prime Factor (SPF),
 * which allows for O(log N) prime factorization of any number.
 */

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000005;
int spf[MAXN]; // Smallest Prime Factor
vector<int> primes;

// Linear Sieve O(N)
void sieve() {
    for (int i = 2; i < MAXN; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || (long long)i * p >= MAXN) break;
            spf[i * p] = p;
        }
    }
}

// Fast Factorization O(log N) using SPF
vector<int> getFactorization(int x) {
    vector<int> factors;
    while (x > 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int main() {
    sieve();

    cout << "First 10 primes: ";
    for (int i = 0; i < 10; i++) cout << primes[i] << " ";
    cout << endl;

    int num = 120;
    vector<int> factors = getFactorization(num);
    cout << "Prime factors of " << num << ": ";
    for (int f : factors) cout << f << " ";
    cout << endl;

    return 0;
}
