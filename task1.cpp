#include <iostream>
using namespace std;
void inputIDs(int arr[], int n) {
    if (n <= 0) {
        return; 
    }
    cout << "Enter " << n << " student IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
//Searches for the target using Linear Search
int linearSearch(int arr[], int n, int target) {
    // Loop from index 0 to n - 1
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return immediately when the target is found
        }
    }
    return -1; 
}
// Function to display the search result
void displayResult(int index) {
    if (index != -1) {
        cout << "Expected result: Index " << index << endl;
    } else {
        cout << "Expected result: Not found" << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of students (array size): ";
    cin >> n;
    int arr[100]; 
    inputIDs(arr, n);

    int target;
    cout << "Enter the target ID to search: ";
    cin >> target;
    int index = linearSearch(arr, n, target);
    displayResult(index);

    return 0;
}