/**
 * ⚡ Fast I/O: Why and How?
 * 
 * In Competitive Programming, handling 1 million numbers with standard 'cin' 
 * can take > 2 seconds. Proper optimization brings it down to < 0.2 seconds.
 */

#include <iostream>

using namespace std;

/**
 * 1. ios_base::sync_with_stdio(false);
 * -----------------------------------
 * By default, C++ cin/cout stays in "sync" with C's scanf/printf.
 * This synchronization makes sure you can mix both in one program safely.
 * However, this sync is VERY SLOW. We turn it off for CP.
 * 
 * IMPORTANT: If you use this, DON'T use scanf/printf anymore!
 */

/**
 * 2. cin.tie(NULL);
 * ----------------
 * Normally, 'cin' is "tied" to 'cout'. Before you read input, C++ flushes 
 * the output buffer to make sure any prompts (like "Enter name:") are visible.
 * In CP, there are no interactive prompts. We want to read input as fast as 
 * possible without caring about flushing output.
 */

/**
 * 3. \n vs endl
 * -------------
 * 'endl' does two things:
 *    a) Prints a newline character.
 *    b) Forces a "flush" (clearing the buffer).
 * Flushing is very expensive. Use "\n" instead. 
 * It only flushes when the buffer is full (efficient).
 */

int main() {
    // Standard setup for almost EVERY CP problem
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // cin >> n; // This is now blazing fast!

    cout << "Standard CP setup complete.\n";

    return 0;
}
