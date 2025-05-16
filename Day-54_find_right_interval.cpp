#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<pair<int, int>> &map, int target)
{
    int n = map.size();
    int st = 0, end = n - 1, ans = -1;

    // if(map[n-1].first < target) return -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (map[mid].first >= target)
        {
            ans = map[mid].second;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<pair<int, int>> map;

    for (int i = 0; i < n; i++)
    {
        map.push_back({intervals[i][0], i});
    }
    sort(map.begin(), map.end());

    vector<int> result(n, -1);
    for (int i = 0; i < n; i++)
    {
        result[i] = binary_search(map, intervals[i][1]);
    }
    return result;
}
int main()
{
    vector<vector<int>> intervals = {{3,4},{2,3},{1,2}};
    vector<int> result = findRightInterval(intervals);

    for(auto x : result){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}