// Problem Statement:
// Given an array of size N, reverse every subarray of size K. If the remaining elements are fewer than K, reverse them as well.

#include <iostream>
using namespace std;

void insert(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void reverseInGroups(int a[], int n, int k) {
    for (int i = 0; i < n; i += k) {  // Process every group of size K
        int left = i;
        int right = min(i + k - 1, n - 1);  // Ensure we don’t go out of bounds

        while (left < right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the group size K: ";
    cin >> k;

    int a[n];
    cout << "Enter the elements of the array: ";
    insert(a, n);

    cout << "\nEntered Array is:\n";
    printArray(a, n);

    reverseInGroups(a, n, k); // In-place reversal

    cout << "Reversed array is:\n";
    printArray(a, n);

    return 0;
}