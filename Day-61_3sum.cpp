#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            int total = nums[i] + nums[j] + nums[k];
            if (total > 0)
            {
                k--;
            }
            else if (total < 0)
            {
                j++;
            }
            else
            {
                result.push_back({nums[i], nums[j], nums[k]});
                j++;

                while (nums[j] == nums[j - 1] && j < k)
                {
                    j++;
                }
            }
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);
    for(auto i:result){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"  ";
    }
    cout<<endl;
    return 0;
}