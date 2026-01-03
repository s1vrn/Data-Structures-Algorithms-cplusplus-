/**
 * Bit Manipulation Tricks
 * 
 * Commonly used to optimize space and time.
 * Key Concepts: AND, OR, XOR, Left Shift, Right Shift.
 */

#include <iostream>

using namespace std;

void printBinary(int n) {
    for (int i = 10; i >= 0; --i) {
        cout << ((n >> i) & 1);
    }
    cout << "\n";
}

int main() {
    int a = 5;  // 101
    int b = 7;  // 111

    // 1. Basic Operations
    cout << "5 & 7 = " << (a & b) << "\n";  // 101 -> 5
    cout << "5 | 7 = " << (a | b) << "\n";  // 111 -> 7
    cout << "5 ^ 7 = " << (a ^ b) << "\n";  // 010 -> 2 (XOR)
    
    // 2. Left and Right Shift
    cout << "5 << 1 = " << (a << 1) << "\n"; // 1010 -> 10 (Multiply by 2)
    cout << "5 >> 1 = " << (a >> 1) << "\n"; // 10 -> 2 (Divide by 2)

    // 3. Tricks
    int x = 4; // 100
    // Check if even/odd
    if(x & 1) cout << x << " is Odd\n";
    else cout << x << " is Even\n"; // Output: Even

    // Check if power of 2
    // If x is power of 2, it has only one set bit. x-1 has all lower bits set.
    // So x & (x-1) should be 0.
    // Caution: 0 checks as true with this trick, handle separately if needed.
    x = 8;
    if(x && !(x & (x - 1))) cout << x << " is Power of 2\n";

    // Set the ith bit
    int n = 0;
    int i = 2; // Set 2nd bit (0-indexed)
    n = n | (1 << i); 
    cout << "After setting 2nd bit: "; printBinary(n); // 000100

    // Unset ith bit
    n = 7; // 111
    n = n & ~(1 << 1); // Unset 1st bit
    cout << "After unsetting 1st bit of 7: "; printBinary(n); // 101 (5)

    // Toggle ith bit
    n = 5; // 101
    n = n ^ (1 << 1); // Toggle 1st bit (0->1 or 1->0)
    cout << "After toggling 1st bit of 5: "; printBinary(n); // 111 (7)

    // Extract lowest set bit (0010100 -> 0000100)
    int y = 12; // 1100
    int lowest_bit = y & (-y);
    cout << "Lowest set bit of 12 (1100): " << lowest_bit << " (4)\n";

    return 0;
}
