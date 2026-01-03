/**
 * Priority Queue (Max-Heap / Min-Heap)
 * 
 * A specialized data structure that provides O(log N) access to the largest (or smallest) element.
 * Useful for: Dijkstra's, Prim's, K-th largest element, Scheduling.
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // 1. Max-Heap (Default in C++)
    // Keeps largest element at top.
    priority_queue<int> max_pq;

    max_pq.push(10);
    max_pq.push(30);
    max_pq.push(20);
    max_pq.push(5);

    cout << "--- Max Heap ---\n";
    cout << "Top element: " << max_pq.top() << "\n"; // 30
    
    max_pq.pop(); // Removes 30
    cout << "New Top: " << max_pq.top() << "\n"; // 20


    // 2. Min-Heap
    // Keeps smallest element at top.
    // Syntax: priority_queue<Type, Container, Comparator>
    priority_queue<int, vector<int>, greater<int>> min_pq;

    min_pq.push(10);
    min_pq.push(30);
    min_pq.push(20);
    min_pq.push(5);

    cout << "\n--- Min Heap ---\n";
    cout << "Top element: " << min_pq.top() << "\n"; // 5
    
    min_pq.pop(); // Removes 5
    cout << "New Top: " << min_pq.top() << "\n"; // 10

    return 0;
}
