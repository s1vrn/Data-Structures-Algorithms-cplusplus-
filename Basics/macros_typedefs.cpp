/**
 * ⌨️ Shortcuts: Macros and Typedefs
 * 
 * In Competitive Programming, we often use shortcuts to type long keywords faster.
 */

#include <iostream>
#include <vector>

using namespace std;

// 1. Typedefs (Giving new names to types)
// Syntax: typedef OldType NewName;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// 2. Using (Modern alternative to typedef)
using ld = long double;

// 3. Macros (#define)
// Macros literally replace text before the code is compiled.
#define F first
#define S second
#define PB push_back
#define MP make_pair

// A common loop macro
#define rep(i, a, b) for (int i=a; i<b; i++)

int main() {
    // Using typedefs
    ll bigNum = 1e18;
    vi myVector = {1, 2, 3};
    
    // Using macros
    myVector.PB(4);
    
    pii myPair = MP(10, 20);
    cout << "First: " << myPair.F << ", Second: " << myPair.S << "\n";

    // Using the rep macro
    rep(i, 0, 5) {
        cout << i << " ";
    }
    cout << "\n";

    /**
     * CAUTION: Macros can be hard to debug. 
     * Use them moderately until you are comfortable!
     */

    return 0;
}
