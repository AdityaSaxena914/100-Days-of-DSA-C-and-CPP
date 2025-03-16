// Problem:
// "First Longest Subarray with Sum K"
// Given an array of integers and an integer K, find the length of the first longest subarray that sums to K.
// Constraints:
// Array can contain negative numbers.
// Optimize for O(n) if possible.
// Hint: Use a hashmap to track prefix sums.
#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int longestSubarrayWithSumK(vector<int> &arr, int K)
{
    unordered_map<int, int> prefixSumMap;
    int currentSum = 0;
    int maxLength = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        currentSum += arr[i];

        // If the current sum equals K, update maxLength
        if (currentSum == K)
        {
            maxLength = i + 1;
        }

        // Check if currentSum - K exists in the map
        if (prefixSumMap.find(currentSum - K) != prefixSumMap.end())
        {
            maxLength = max(maxLength, i - prefixSumMap[currentSum - K]);
        }

        // Store currentSum with its index (only the first occurrence)
        if (prefixSumMap.find(currentSum) == prefixSumMap.end())
        {
            prefixSumMap[currentSum] = i;
        }
    }

    return maxLength;
}
int main()
{
    int n, K;
    cout << "Size: ";
    cin >> n;
    vector<int> arr(n);
    insert(arr);
    cout << "Array: ";
    printArray(arr);
    cout << "K: ";
    cin >> K;
    cout << "\nLongest subarray with sum K: ";
    int result = longestSubarrayWithSumK(arr, K);
    if (result == 0)
    {
        cout << "No such subarray exists";
    }
    else
    {
        cout << "Longest subarray of sum: " << K << " is " << result << endl;
    }
    return 0;
}