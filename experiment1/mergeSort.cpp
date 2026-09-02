//PALAK BAJWAN
//25/DA/049
//MERGE SORT
#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted parts
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    // Compare elements from both halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right half
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// ---------------- RECURSIVE MERGE SORT ----------------

void mergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Sort left half
    mergeSortRecursive(arr, left, mid);

    // Sort right half
    mergeSortRecursive(arr, mid + 1, right);

    // Merge both halves
    merge(arr, left, mid, right);
}

// ---------------- ITERATIVE MERGE SORT ----------------

void mergeSortIterative(vector<int>& arr) {
    int n = arr.size();

    // Current size of subarrays to merge
    for (int size = 1; size < n; size *= 2) {

        // Merge adjacent subarrays
        for (int left = 0; left < n - 1; left += 2 * size) {

            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);

            // If there is a second half
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

// ---------------- DISPLAY ARRAY ----------------

void display(vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// ---------------- MAIN ----------------

int main() {

    vector<int> arr1 = {38, 27, 43, 3, 9, 82, 10};
    vector<int> arr2 = arr1;

    cout << "Original Array: ";
    display(arr1);

    // Recursive Merge Sort
    mergeSortRecursive(arr1, 0, arr1.size() - 1);

    cout << "After Recursive Merge Sort: ";
    display(arr1);

    // Iterative Merge Sort
    mergeSortIterative(arr2);

    cout << "After Iterative Merge Sort: ";
    display(arr2);

    return 0;
}
