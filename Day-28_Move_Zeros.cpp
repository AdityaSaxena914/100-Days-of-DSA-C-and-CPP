// 📌 Problem: Move Target to End (Advanced Version of Leetcode #283)
// 🔹 Problem Statement:
// You are given an array nums[] of integers and a target value target. Write a function to move all occurrences of the target value to the end of the array while maintaining the relative order of the non-target elements.

// Constraints:

// Do this in O(n) time complexity.
// Use constant extra space — modify the array in place.
#include<iostream>
#include<vector>
using namespace std;
void insert(vector<int> &nums, int n){
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
}
void printArray(vector<int> &nums){
    for(int i: nums){
        cout << i << " ";
    }
    cout << endl;
}
void moveZeros(vector<int> &nums, int target){
    int j = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] != target){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    insert(nums, n);
    cout << "\nEntered Array is:\n";
    printArray(nums);
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    cout << "Modified Array is:\n";
    moveZeros(nums, target);
    printArray(nums);
    return 0;
}