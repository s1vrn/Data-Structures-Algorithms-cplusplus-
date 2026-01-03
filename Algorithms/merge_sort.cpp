/**
 * Merge Sort
 * 
 * Divide and Conquer Algorithm.
 * Time Complexity: O(N log N) in all cases.
 * Space Complexity: O(N) (needs auxiliary array).
 * Stable Sort: Yes.
 */

#include <iostream>
#include <vector>

using namespace std;

// Merge two sorted subarrays arr[left..mid] and arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main function that sorts arr[left..right] using merge()
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Given array is \n";
    printArray(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array is \n";
    printArray(arr);
    return 0;
}
