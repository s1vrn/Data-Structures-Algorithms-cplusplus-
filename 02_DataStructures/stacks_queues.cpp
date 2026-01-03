/**
 * Stacks and Queues
 * 
 * Stack: LIFO (Last In, First Out)
 * Queue: FIFO (First In, First Out)
 * 
 * Both have O(1) complexity for push, pop, and top/front operations.
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void stack_demo() {
    cout << "--- Stack Demo ---\n";
    stack<int> s;

    // 1. Push
    s.push(1);
    s.push(2);
    s.push(3);
    // Stack structure: [1, 2, 3] (Top is 3)

    // 2. Access Top
    cout << "Top element: " << s.top() << "\n"; // 3

    // 3. Pop (Remove top)
    s.pop(); 
    // Stack: [1, 2]

    cout << "New Top: " << s.top() << "\n"; // 2

    // 4. Check empty
    if(!s.empty()) cout << "Stack is not empty\n";
}

void queue_demo() {
    cout << "\n--- Queue Demo ---\n";
    queue<string> q;

    // 1. Push
    q.push("First");
    q.push("Second");
    q.push("Third");
    // Queue structure: ["First", "Second", "Third"] (Front is "First")

    // 2. Access Front
    cout << "Front element: " << q.front() << "\n"; // "First"

    // 3. Pop (Remove front)
    q.pop();
    // Queue: ["Second", "Third"]

    cout << "New Front: " << q.front() << "\n"; // "Second"
}

int main() {
    stack_demo();
    queue_demo();
    return 0;
}
