/**
 * Fast I/O Explanation
 * 
 * In Competitive Programming, input and output speed can sometimes be the difference
 * between Time Limit Exceeded (TLE) and Accepted (AC), especially when dealing with
 * millions of input lines.
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. ios_base::sync_with_stdio(false);
    //    By default, C++ streams (cin/cout) are synchronized with C standard streams (scanf/printf).
    //    This allows you to mix them safely but comes with a performance penalty.
    //    Disabling synchronization speeds up C++ streams significantly.
    ios_base::sync_with_stdio(false);

    // 2. cin.tie(NULL);
    //    By default, cin is tied to cout. This means that before any input operation (cin),
    //    the output buffer (cout) is flushed (printed to screen). This ensures prompt prompts
    //    but is unnecessary for CP and slows down the program.
    //    Untying them prevents this automatic flushing.
    cin.tie(NULL);

    // Note: When using fast I/O, usually avoid using `endl`.
    //       `endl` inserts a newline AND forces a flush.
    //       Use `\n` instead, which is much faster.
    
    cout << "Enter a large number of integers (simulated): \n";
    
    // Example of fast reading
    int n = 10; // Let's pretend we are reading 10^5 integers
    for(int i = 0; i < n; i++) {
        // cin >> x; 
        // cout << x << "\n"; 
    }
    
    cout << "Fast I/O is active!" << "\n";

    return 0;
}
