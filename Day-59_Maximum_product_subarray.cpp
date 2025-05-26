#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int maxSoFar = nums[0], minSoFar = nums[0], result = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        int tempMax = max({nums[i], maxSoFar * nums[i], minSoFar * nums[i]});
        minSoFar = min({nums[i], maxSoFar * nums[i], minSoFar * nums[i]});
        maxSoFar = tempMax;
        result = max(result, maxSoFar);
    }
    return result;
}

int main()
{
    vector<int> nums = {2,3,-2,4};
    cout << maxProduct(nums) << endl;
    return 0;
}