#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int currSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<< maxSubArray(nums)<<endl;
    return 0;
}