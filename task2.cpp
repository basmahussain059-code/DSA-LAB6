#include <iostream>
using namespace std;

// Checks whether the input is sorted in non-decreasing order
bool isSorted(int arr[], int n) {
    // An array of 0 or 1 element is always sorted
    if (n <= 1) {
        return true; 
    }
    // Check if any element is strictly greater than the next one
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to read the registration numbers in ascending order
void inputSortedIDs(int arr[], int n) {
    if (n <= 0) {
        return; // Do nothing for empty arrays
    }
    cout << "Enter " << n << " registration IDs (must be sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

//Iterative Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    // Loop until the search space is exhausted
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; 
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int n;
    cout << "Enter the number of students (array size): ";
    cin >> n;
    int arr[100]; 
    inputSortedIDs(arr, n);
    //Validate if array is sorted
    if (!isSorted(arr, n)) {
        cout << "Error: The array must be sorted in ascending order for Binary Search to work!" << endl;
        return 1;
    }

    //Get target ID
    int target;
    cout << "Enter the target ID to search: ";
    cin >> target;
    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1) {
        cout << "Expected result: Index " << index << endl;
    } else {
        cout << "Expected result: Not found" << endl;
    }

    return 0;
}