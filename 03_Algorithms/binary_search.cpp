/**
 * Binary Search
 * 
 * Used to find an element in a SORTED array in O(log N).
 * Also used to find the answer when the answer space is monotonic (Binary Search on Answer).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Manual Binary Search Implementation
int binarySearch(const vector<int>& v, int target) {
    int left = 0;
    int right = v.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (v[mid] == target) return mid; // Found
        if (v[mid] < target) left = mid + 1; // Look in right half
        else right = mid - 1; // Look in left half
    }
    return -1; // Not found
}

int main() {
    vector<int> v = {1, 3, 5, 7, 9, 11, 13};

    // 1. Manual Search
    int index = binarySearch(v, 7);
    cout << "Found 7 at index: " << index << "\n";

    // 2. STL Binary Search Functions
    // binary_search(begin, end, val) -> Returns true/false
    bool found = binary_search(v.begin(), v.end(), 5);
    if(found) cout << "5 is present via STL\n";

    // 3. lower_bound & upper_bound (Crucial for CP)
    // lower_bound: iterator to first element >= value
    // upper_bound: iterator to first element > value

    auto it = lower_bound(v.begin(), v.end(), 6); 
    // v has no 6, next element >= 6 is 7
    cout << "Lower bound of 6 points to: " << *it << "\n";

    return 0;
}
