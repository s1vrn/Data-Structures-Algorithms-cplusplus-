/**
 * Tutorial 04: Loops (For, While)
 * 
 * Used to repeat code multiple times.
 */

#include <iostream>

using namespace std;

int main() {
    // 1. For Loop
    // Use when you know exactly how many times to repeat.
    // Syntax: for (start; condition; update)
    cout << "--- For Loop ---\n";
    for (int i = 1; i <= 5; i++) {
        cout << "Count: " << i << "\n";
    }

    // 2. While Loop
    // Use when you want to repeat UNTIL a condition becomes false.
    cout << "\n--- While Loop ---\n";
    int j = 1;
    while (j <= 5) {
        cout << "While Count: " << j << "\n";
        j++; // Don't forget to increase j, or loop runs forever!
    }

    // 3. Do-While Loop
    // Runs at least once, then checks condition.
    cout << "\n--- Do-While Loop ---\n";
    int k = 10;
    do {
        cout << "This runs once even if k > 5 (k is " << k << ")\n";
    } while (k < 5);

    return 0;
}
