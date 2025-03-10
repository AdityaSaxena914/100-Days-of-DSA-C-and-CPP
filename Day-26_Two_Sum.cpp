// Problem Statement: Given an array of integers nums and an integer target
// return the indices of the two numbers such that they add up to target.
// You cannot use the same element twice.
// Return the answer in any order.
// Assume that exactly one solution exists.
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void insert(vector<int>& a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++) {
        int diff = target - arr[i];
        if (m.find(diff) != m.end()) {
            return {m[diff], i};
        }
        m[arr[i]] = i;
    }
    
    return {};
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    insert(arr, n);
    cout << "\nEntered Array is:\n";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    int target;
    cout << "Enter the target sum: ";
    cin >> target;
    vector<int> result = twoSum(arr, target);
    if (!result.empty()) {
        cout << "The indices are: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No such pair exists\n";
    }
    return 0;
}