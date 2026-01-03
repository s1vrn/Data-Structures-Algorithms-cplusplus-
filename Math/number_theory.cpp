/**
 * Number Theory Basics
 * 
 * 1. GCD (Greatest Common Divisor) & LCM (Least Common Multiple)
 * 2. Sieve of Eratosthenes (Generating Primes efficiently)
 * 3. Modular Arithmetic Basics
 */

#include <iostream>
#include <vector>
#include <numeric> // for std::gcd in C++17

using namespace std;

// 1. GCD and LCM
// GCD(a, b) = GCD(b, a % b) [Euclidean Algorithm]
// LCM(a, b) = (a * b) / GCD(a, b)
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b; // Divide first to prevent overflow
}

// 2. Sieve of Eratosthenes - O(N log log N)
// Finds all primes up to MAX_N
const int MAX_N = 1000000;
vector<bool> is_prime(MAX_N + 1, true);
vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAX_N; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_N; i += p)
                is_prime[i] = false;
        }
    }
    
    // Store primes for easy access
    for(int p = 2; p <= MAX_N; p++) {
        if(is_prime[p]) {
            primes.push_back(p);
        }
    }
}

// 3. Modular Exponentiation - (base^exp) % mod - O(log exp)
long long power(long long base, long long exp, int mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    // GCD/LCM Demo
    cout << "GCD(12, 18) = " << gcd(12, 18) << "\n";
    cout << "LCM(12, 18) = " << lcm(12, 18) << "\n";
    
    // Sieve Demo
    sieve();
    cout << "Number of primes up to " << MAX_N << ": " << primes.size() << "\n";
    cout << "First 10 primes: ";
    for(int i=0; i<10; i++) cout << primes[i] << " ";
    cout << "\n";

    // Modular Exponentiation Demo
    // Calculate 2^10 % 1000
    cout << "2^10 % 1000 = " << power(2, 10, 1000) << "\n";

    return 0;
}
