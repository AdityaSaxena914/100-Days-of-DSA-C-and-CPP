#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> result;
    if (n == 1)
    {
        int a = nums[0];
        result.push_back(a);
        return result;
    }
    unordered_map<int, int> mp;
    for (auto &pairs : nums)
    {
        mp[pairs]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto &pair : mp)
    {
        minHeap.push({pair.second, pair.first});
        if (minHeap.size() > k)
        {
            minHeap.pop(); // Remove least frequent
        }
    }

    while (!minHeap.empty())
    {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}
int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k;

    cin>>k;

    vector<int>result = topKFrequent(nums,k);

    for(auto i: result){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}