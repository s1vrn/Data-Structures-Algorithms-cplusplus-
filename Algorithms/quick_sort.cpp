/**
 * Quick Sort
 * 
 * Divide and Conquer Algorithm.
 * Time Complexity: O(N log N) average, O(N^2) worst case.
 * Space Complexity: O(log N) stack space.
 * Not Stable (usually).
 */

#include <iostream>
#include <vector>

using namespace std;

// Partition: Places pivot at correct position, 
// moves smaller to left, larger to right.
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing last element as pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    
    cout << "Original array: \n";
    printArray(arr);

    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: \n";
    printArray(arr);
    
    return 0;
}
