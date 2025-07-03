#include <bits/stdc++.h>
using namespace std;
double findMaxAverage(vector<int> &nums, int k)
{
    double sum = 0;
    int n = nums.size();

    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    double maxi = sum;

    for (int i = k; i < n; i++)
    {
        sum = sum - nums[i - k] + nums[i];
        maxi = max(maxi, sum);
    }

    return maxi / k;
}
int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    if (k <= 0 || k > nums.size())
    {
        cout << "Invalid input. k must be a positive integer and less than or equal to the size of the array." << endl;
        return 1;
    }
    double result = findMaxAverage(nums, k);
    cout << "Maximum average of subarray of size " << k << " is: "<< result << endl;

    return 0;
}