/**
 * Two Pointers Technique
 * 
 * Often used on sorted arrays to find pairs or subarrays with certain properties in O(N).
 * Example: Find two numbers in a sorted array that sum up to Target.
 */

#include <iostream>
#include <vector>

using namespace std;

void findPairSum(vector<int>& v, int target) {
    int left = 0;
    int right = v.size() - 1;
    bool found = false;

    while(left < right) {
        int currentSum = v[left] + v[right];

        if(currentSum == target) {
            cout << "Found pair: " << v[left] << " + " << v[right] << " = " << target << "\n";
            found = true;
            break; // Stop after first pair
        } 
        else if(currentSum < target) {
            left++; // Need a bigger sum
        } 
        else {
            right--; // Need a smaller sum
        }
    }

    if(!found) cout << "No pair found.\n";
}

int main() {
    // Array MUST be sorted for this logic
    vector<int> v = {1, 3, 4, 6, 8, 10, 14};
    int target = 14;

    findPairSum(v, target);

    return 0;
}
