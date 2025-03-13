// Three Sum Problem (LeetCode #15):
// Given an array nums of integers and a target value, find all unique triplets (nums[i], nums[j], nums[k]) such that:

// i != j != k
// nums[i] + nums[j] + nums[k] == target
// Constraints:

// You may not use the same element twice.
// The solution should avoid duplicate triplets.
// Return the triplets in any order.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void threeSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    bool found = false;
    for (int i = 0; i < n - 2; i++)
    {
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target)
            {
                cout << "(" << nums[i] << ", " << nums[left] << ", " << nums[right] << ")\n";
                found = true;
                // Skip duplicates for left and right pointers
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    if (!found)
    {
        cout << "No such triplet found!\n";
    }
}
void insert(vector<int> &nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}
void printArray(vector<int> &nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
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

    cout << "Triplets with the given sum are:\n";
    threeSum(nums, target);

    return 0;
}