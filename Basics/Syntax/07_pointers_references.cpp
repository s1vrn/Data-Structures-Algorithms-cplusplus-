/**
 * Tutorial 07: Pointers and References
 * 
 * Pointers and References allow us to work with memory addresses.
 * 
 * - Pointer (*): A variable that stores the memory address of another variable.
 * - Reference (&): An alias (another name) for an existing variable.
 * - Pass-by-Reference: Allowing a function to modify the original variable.
 */

#include <iostream>

using namespace std;

// Function using Pass-by-Value (Copy is created)
void incrementByValue(int n) {
    n++; // Only the copy is changed
}

// Function using Pass-by-Reference (Original is changed)
void incrementByReference(int &n) {
    n++; // Original variable is changed
}

int main() {
    // 1. References
    int original = 10;
    int &ref = original; // ref is now an alias for original

    cout << "Original: " << original << "\n";
    ref = 20; // Changing ref changes original
    cout << "Original after ref change: " << original << "\n";

    // 2. Pointers
    int val = 50;
    int *ptr = &val; // ptr stores the address of val

    cout << "Value of val: " << val << "\n";
    cout << "Address of val: " << &val << "\n";
    cout << "Pointer ptr stores: " << ptr << "\n";
    cout << "Value ptr points to (dereferencing): " << *ptr << "\n";

    *ptr = 100; // Changing value at address changes val
    cout << "val after pointer change: " << val << "\n";

    // 3. Pass-by-Reference in Functions
    int x = 5;
    incrementByValue(x);
    cout << "x after incrementByValue: " << x << " (No change)\n";

    incrementByReference(x);
    cout << "x after incrementByReference: " << x << " (Changed!)\n";

    return 0;
}
