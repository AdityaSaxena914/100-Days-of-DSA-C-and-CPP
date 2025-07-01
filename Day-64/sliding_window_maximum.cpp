#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> result;
    deque<int> dq;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    // Output: 3 3 5 5 6 7

    return 0;
}