// Implementing Hash Mapping in C++
// Print the elements that are common in at least 2 arrays

#include <iostream>
#include <unordered_map>
using namespace std;

void Insert(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void FindElement(int arr[], int arr2[], int arr3[], int n, int n1, int n2) {
    unordered_map<int, int> m;

    // Insert elements in the map
    for (int i = 0; i < n; i++) m[arr[i]]++;
    for (int i = 0; i < n1; i++) m[arr2[i]]++;
    for (int i = 0; i < n2; i++) m[arr3[i]]++;

    // Print elements appearing in at least 2 arrays
    for (auto i : m) {
        if (i.second >= 2) {
            cout << i.first << " ";
        }
    }
    cout << endl;
}

int main() {
    int n, n1, n2;

    cout << "Enter the size of the first array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the first array: ";
    Insert(arr, n);

    cout << "Enter the size of the second array: ";
    cin >> n1;
    int arr2[n1];
    cout << "Enter the elements of the second array: ";
    Insert(arr2, n1);

    cout << "Enter the size of the third array: ";
    cin >> n2;
    int arr3[n2];
    cout << "Enter the elements of the third array: ";
    Insert(arr3, n2);

    cout << "\nEntered Arrays are:\n";
    cout << "Array 1: ";
    printArray(arr, n);
    cout << "Array 2: ";
    printArray(arr2, n1);
    cout << "Array 3: ";
    printArray(arr3, n2);

    cout << "\nThe elements that are common in at least 2 arrays are: ";
    FindElement(arr, arr2, arr3, n, n1, n2);

    return 0;
}
