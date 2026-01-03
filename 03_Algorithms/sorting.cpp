/**
 * Sorting in C++
 * 
 * We rarely implement Bubble/Merge/Quick sort from scratch in CP.
 * We use std::sort which is highly optimized (IntroSort: Hybrid of Quick, Heap, and Insertion Sort).
 * Complexity: O(N log N).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom Comparator
// Sorts in descending order
bool compareDesc(int a, int b) {
    return a > b; 
}

struct Person {
    string name;
    int age;
    int score;
};

// Sort by score descending, then by age ascending
bool comparePerson(const Person& a, const Person& b) {
    if(a.score != b.score) return a.score > b.score; 
    return a.age < b.age;
}

int main() {
    vector<int> v = {4, 2, 5, 1, 3};

    // 1. Basic Sort (Ascending)
    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for(int x : v) cout << x << " "; 
    cout << "\n";

    // 2. Sort Descending using simple Comparator
    sort(v.begin(), v.end(), compareDesc);
    // Alternatively: sort(v.begin(), v.end(), greater<int>());

    // 3. Struct Sorting
    vector<Person> people = {
        {"Alice", 25, 100},
        {"Bob", 20, 90},
        {"Charlie", 22, 100}
    };

    sort(people.begin(), people.end(), comparePerson);

    cout << "People Sorted:\n";
    for(auto& p : people) {
        cout << p.name << " (Age: " << p.age << ", Score: " << p.score << ")\n";
    }

    return 0;
}
