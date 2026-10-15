#include <iostream>
using namespace std;
void displayArray(int arr[], int n) {
    if (n == 0) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0; 
    int j = 0; 
    int k = left; 
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
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;      // Free the dynamically allocated memory
    delete[] R;
}
void mergeSort(int arr[], int left, int right) {
    // Base case
    if (left >= right) {
        return; 
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);     // Merge the sorted halves
}
int main() {
    int n;
    cout << "Enter the number of student marks: ";
    cin >> n;
    int arr[100]; // Using a fixed size array for simplicity
    if (n > 0) {
        cout << "Enter the marks: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    cout << "Before sorting: ";
    displayArray(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "After sorting:  ";
    displayArray(arr, n);
    return 0;
}