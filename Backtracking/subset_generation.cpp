/**
 * 🧩 Subset Generation
 * 
 * Generating all possible subsets of a set is a fundamental technique.
 * For a set of size N, there are 2^N subsets.
 */

#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(int idx, vector<int>& nums, vector<int>& current) {
    // Print current subset
    cout << "{ ";
    for (int x : current) cout << x << " ";
    cout << "}\n";

    for (int i = idx; i < nums.size(); i++) {
        current.push_back(nums[i]); // Include nums[i]
        generateSubsets(i + 1, nums, current); // Recurse
        current.pop_back(); // Exclude nums[i] (Backtrack)
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> current;
    
    cout << "All subsets of {1, 2, 3}:" << endl;
    generateSubsets(0, nums, current);

    return 0;
}
