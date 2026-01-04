/**
 * 📦 Deque (Double-ended Queue)
 * 
 * std::deque is a sequence container that allows fast insertion and deletion
 * at both its beginning and its end. Unlike vector, it doesn't guarantee
 * contiguous memory, but it's more efficient for push_front/pop_front.
 */

#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dq;

    // 1. Insertion
    dq.push_back(10);  // {10}
    dq.push_front(20); // {20, 10}
    dq.push_back(30);  // {20, 10, 30}

    cout << "Front: " << dq.front() << endl; // 20
    cout << "Back: " << dq.back() << endl;   // 30

    // 2. Deletion
    dq.pop_front(); // {10, 30}
    dq.pop_back();  // {10}

    // 3. Iteration
    dq.push_back(40);
    dq.push_front(50);
    cout << "Contents: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // 4. Access
    cout << "Element at index 1: " << dq[1] << endl;

    /**
     * Use cases:
     * - Sliding window maximum (Monotonic Queue).
     * - Problems needing access to both ends with growth on both sides.
     */

    return 0;
}
