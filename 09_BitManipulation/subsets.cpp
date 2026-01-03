/**
 * Generating Subsets (Power Set) using Bitmask
 * 
 * If we have N elements, there are 2^N subsets.
 * Iterate from 0 to 2^N - 1. Each bit represents an element.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printSubsets(vector<char>& set) {
    int n = set.size();
    int power_set_size = pow(2, n);

    for (int counter = 0; counter < power_set_size; counter++) {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            // Check if jth bit in the counter is set
            if ((counter & (1 << j)) != 0)
                cout << set[j] << " ";
        }
        cout << "}\n";
    }
}

int main() {
    vector<char> set = {'a', 'b', 'c'};
    printSubsets(set);
    return 0;
}
