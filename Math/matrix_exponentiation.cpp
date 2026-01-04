/**
 * 🧬 Matrix Exponentiation
 * 
 * Matrix exponentiation allows us to solve linear recurrence relations 
 * like Fibonacci in O(K^3 log N) time, where K is the matrix size.
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<ll>> mat;
    int size;

    Matrix(int s) : size(s) {
        mat.resize(size, vector<ll>(size, 0));
    }

    static Matrix identity(int s) {
        Matrix res(s);
        for (int i = 0; i < s; i++) res.mat[i][i] = 1;
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix power(Matrix a, ll b) {
    Matrix res = Matrix::identity(a.size);
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// Fibonacci: F(n) = F(n-1) + F(n-2)
// [F(n)  ] = [1 1] [F(n-1)]
// [F(n-1)]   [1 0] [F(n-2)]
ll fib(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    Matrix transition(2);
    transition.mat[0][0] = 1; transition.mat[0][1] = 1;
    transition.mat[1][0] = 1; transition.mat[1][1] = 0;

    transition = power(transition, n - 1);

    // Initial state: F(1)=1, F(0)=0
    return (transition.mat[0][0] * 1 + transition.mat[0][1] * 0) % MOD;
}

int main() {
    ll n = 10;
    cout << "Fibonacci(" << n << "): " << fib(n) << endl; // F(10) = 55
    
    n = 1000000000000000000LL; // 10^18
    cout << "Fibonacci(10^18) % MOD: " << fib(n) << endl;

    return 0;
}
