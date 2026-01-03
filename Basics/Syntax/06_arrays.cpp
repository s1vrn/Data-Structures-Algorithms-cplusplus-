/**
 * Tutorial 06: Arrays and Vectors
 * 
 * Arrays store multiple values of the same type.
 * - C-Style Array: Fixed size.
 * - std::vector: Dynamic size (Preferred in C++).
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. C-Style Array
    // Size must be known at compile time usually.
    cout << "--- C-Style Array ---\n";
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Accessing elements (0-indexed)
    cout << "First element: " << arr[0] << "\n";
    
    // Changing element
    arr[1] = 99;
    cout << "Second element: " << arr[1] << "\n";

    // Loop through array
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";


    // 2. std::vector (Dynamic Array)
    cout << "\n--- std::vector ---\n";
    vector<int> v;

    // Adding elements
    v.push_back(100);
    v.push_back(200);
    
    cout << "Vector size: " << v.size() << "\n";
    cout << "Vector first element: " << v[0] << "\n";

    // Modern "Range-based For Loop"
    // Read as: "For each x in v"
    cout << "Vector contents: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
