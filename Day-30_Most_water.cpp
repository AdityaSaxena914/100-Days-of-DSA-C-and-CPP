// Advanced Version of LeetCode #11: Container With Most Water
// Problem Statement:
// You are given an integer array height of length n, where each element represents the height of a vertical line drawn on the x-axis.
// Find two lines that, together with the x-axis, form a container such that the container holds the most water.
// Advanced Version:
// In this version, you are allowed to remove up to k elements from the array to maximize the water.
// Return the maximum amount of water a container can store after optimally removing up to k elements.
// Constraints:
// 2 ≤ n ≤ 10<sup>5</sup>
// 0 ≤ height[i] ≤ 10<sup>4</sup>
// 0 ≤ k < n

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insert(vector<int> &height)
{
    for (int i = 0; i < height.size(); i++)
    {
        cin >> height[i];
    }
}

void printArray(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int maxWaterWithRemovals(vector<int> &height, int k)
{
    int n = height.size();

    // Edge cases
    if (n < 2)
        return 0;
    if (n == 2)
        return min(height[0], height[1]);

    int i = 0, j = n - 1;
    int maxWater = 0;

    // Allow k removals to maximize the area
    while (i < j)
    {
        int h = min(height[i], height[j]);
        int l = j - i;
        maxWater = max(maxWater, h * l);

        // removing the smaller height to potentially increase the area
        if (height[i] < height[j])
        {
            if (k > 0)
            {
                i++; // Remove left container
                k--;
            }
            else
            {
                j--;
            }
        }
        else
        {
            if (k > 0)
            {
                j--; // Remove right container
                k--;
            }
            else
            {
                i++;
            }
        }
    }
    return maxWater;
}
int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter the elements of the array: ";
    insert(height);
    cout << "Enter the number of removals (k): ";
    cin >> k;
    cout << "Entered Array: ";
    printArray(height);
    int result = maxWaterWithRemovals(height, k);
    cout << "Maximum Water after " << k << " removals: " << result << endl;
    return 0;
}
