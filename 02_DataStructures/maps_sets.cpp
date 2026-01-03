/**
 * Sets and Maps in C++
 * 
 * std::set: A collection of unique elements, sorted automatically.
 * std::map: A collection of key-value pairs, sorted by key.
 * 
 * Underlying implementation: Balanced Binary Search Tree (Red-Black Tree).
 * Operations (insert, find, erase) take O(log N).
 */

#include <iostream>
#include <set>
#include <map>

using namespace std;

void set_demo() {
    cout << "--- Set Demo ---\n";
    set<int> s;

    // 1. Insertion - O(log N)
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(5); // Duplicate, will not be added

    // Elements are stored as {5, 10, 20}

    // 2. Checking existence - O(log N)
    if(s.count(10)) cout << "10 is present\n";
    else cout << "10 is not present\n";

    // 3. Size
    cout << "Set size: " << s.size() << "\n";

    // 4. Erase - O(log N)
    s.erase(10);

    // 5. Iterating (In-order, so sorted)
    cout << "Set elements: ";
    for(int x : s) cout << x << " ";
    cout << "\n";
}

void map_demo() {
    cout << "\n--- Map Demo ---\n";
    map<string, int> m;

    // 1. Insertion / Access - O(log N)
    m["apple"] = 5;
    m["banana"] = 10;
    m["cherry"] = 2;

    // 2. Accessing
    cout << "Bananas: " << m["banana"] << "\n";

    // Note: If you access a key that doesn't exist, it creates it with default value (0 for int)
    cout << "Durian (new): " << m["durian"] << "\n"; 

    // 3. Checking existence without creating
    if(m.find("apple") != m.end()) {
        cout << "Apple is in the map\n";
    }

    // 4. Iterating
    for(auto p : m) {
        // p.first is key, p.second is value
        cout << p.first << ": " << p.second << "\n";
    }
}

int main() {
    set_demo();
    map_demo();
    return 0;
}
