#include <bits/stdc++.h>
using namespace std;
int findLucky(vector<int> &arr)
{
    unordered_map<int, int> map;
    int ans = -1;
    for (int num : arr)
    {
        map[num]++;
    }
    for (auto &it : map)
    {
        if (it.first == it.second)
        {
            ans = max(it.first, ans);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {2, 2, 3, 4};
    int res = findLucky(arr);
    cout << "Lucky integer: " << res << endl;

    return 0;
}