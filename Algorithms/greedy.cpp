/**
 * Greedy Algorithms
 * 
 * A greedy algorithm makes the locally optimal choice at each step with the hope of finding a global optimum.
 * Note: Greedy does NOT work for all problems (often requires Dynamic Programming).
 * 
 * Example: Activity Selection / Interval Scheduling
 * Given N activities with start and end times, select the maximum number of non-overlapping activities.
 * Strategy: Always pick the activity that ends FIRST.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, end;
};

// Sort by finish time
bool compareActivities(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    vector<Activity> acts = {
        {1, 3}, {2, 4}, {3, 6}, {5, 7}, {8, 9}, {5, 9}
    };

    // 1. Sort by end time
    sort(acts.begin(), acts.end(), compareActivities);

    // 2. Greedy Selection
    int count = 1;
    int lastEndTime = acts[0].end;

    cout << "Selected Activity: [" << acts[0].start << ", " << acts[0].end << "]\n";

    for(size_t i = 1; i < acts.size(); i++) {
        if(acts[i].start >= lastEndTime) {
            // No overlap, pick it
            count++;
            lastEndTime = acts[i].end;
            cout << "Selected Activity: [" << acts[i].start << ", " << acts[i].end << "]\n";
        }
    }

    cout << "Total activities selected: " << count << "\n";

    return 0;
}
