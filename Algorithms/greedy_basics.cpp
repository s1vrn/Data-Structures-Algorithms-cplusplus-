/**
 * 🍕 Greedy Algorithms
 * 
 * A greedy algorithm makes the locally optimal choice at each step 
 * with the hope of finding the global optimum.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end;
};

// Greedy strategy for Interval Scheduling:
// Always pick the interval that ends earliest.
bool compareIntervals(Interval a, Interval b) {
    return a.end < b.end;
}

int main() {
    vector<Interval> intervals = {{1, 3}, {2, 4}, {3, 6}, {5, 7}, {8, 10}};
    
    // 1. Sort by end time
    sort(intervals.begin(), intervals.end(), compareIntervals);

    int count = 0;
    int last_end_time = -1;

    cout << "Selected Intervals: " << endl;
    for (auto interval : intervals) {
        if (interval.start >= last_end_time) {
            cout << "[" << interval.start << ", " << interval.end << "] ";
            count++;
            last_end_time = interval.end;
        }
    }
    cout << "\n\nMaximum number of non-overlapping intervals: " << count << endl;

    /**
     * Why does this work?
     * By picking the one that ends earliest, we leave the most room possible 
     * for future intervals.
     */

    return 0;
}
