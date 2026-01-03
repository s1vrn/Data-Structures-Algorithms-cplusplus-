/**
 * Vectors in C++ (std::vector)
 * 
 * A vector is a dynamic array that can resize itself automatically.
 * It is one of the most used data structures in Competitive Programming.
 */

#include <iostream>
#include <vector>
#include <algorithm> // For sort, reverse

using namespace std;

int main() {
    // 1. Initialization
    vector<int> v; // Empty vector
    vector<int> v2(5, 10); // Size 5, all elements initialized to 10
    
    // 2. Adding elements (Push Back) - O(1) amortized
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    
    // v is now {1, 5, 3}

    // 3. Accessing elements - O(1)
    cout << "Second element: " << v[1] << "\n"; // Output: 5

    // 4. Size - O(1)
    cout << "Size: " << v.size() << "\n";

    // 5. Sorting - O(N log N)
    sort(v.begin(), v.end());
    // v is now {1, 3, 5}

    // 6. Iterating
    cout << "Vector elements: ";
    for(int x : v) {
        cout << x << " ";
    }
    cout << "\n";

    // 7. Removing last element - O(1)
    v.pop_back(); 
    // v is now {1, 3}

    // 8. Resizing
    v.resize(10); // Size 10, new elements are 0 default
    
    // 9. Clearing
    v.clear(); // Size becomes 0

    return 0;
}
