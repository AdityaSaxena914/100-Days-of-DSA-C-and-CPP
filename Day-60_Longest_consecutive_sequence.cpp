#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{

    if (nums.size() <= 1)
    {
        return nums.size();
    }
    int LongestStreak = 0;

    unordered_set<int> map(nums.begin(), nums.end());
    if (map.size() == 1)
    {
        return 1;
    }
    for (int num : map)
    {
        if (map.find(num - 1) == map.end())
        {
            int currentNum = num;
            int currentStreak = 1;

            while (map.find(currentNum + 1) != map.end())
            {
                currentNum++;
                currentStreak++;
            }

            LongestStreak = max(LongestStreak, currentStreak);
        }
    }

    return LongestStreak;
}
int main()
{
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout<< longestConsecutive(nums)<<endl;
    return 0;
}