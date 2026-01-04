/**
 * 🚀 Policy-Based Data Structures (PBDS)
 * 
 * PBDS are special structures in GCC that provide features not found in standard STL.
 * The most famous is the 'Ordered Set', which allows finding the k-th smallest element
 * and finding the number of elements strictly smaller than X in O(log N).
 */

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Definition of an Ordered Set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set s;

    // 1. Standard Set Operations
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(8);
    s.insert(16);

    // 2. find_by_order(k) - Returns iterator to the k-th smallest element (0-indexed)
    cout << "0th element: " << *s.find_by_order(0) << endl; // 1
    cout << "2nd element: " << *s.find_by_order(2) << endl; // 4
    cout << "4th element: " << *s.find_by_order(4) << endl; // 16

    // 3. order_of_key(X) - Returns number of elements strictly smaller than X
    cout << "Order of 8: " << s.order_of_key(8) << endl;  // 3 (1, 2, 4 are smaller)
    cout << "Order of 9: " << s.order_of_key(9) << endl;  // 4 (1, 2, 4, 8 are smaller)
    cout << "Order of 1: " << s.order_of_key(1) << endl;  // 0

    /**
     * Why use this?
     * Standard std::set doesn't support these two operations efficiently.
     * PBDS is a "lifesaver" in problems involving "Order Statistics".
     */

    return 0;
}
