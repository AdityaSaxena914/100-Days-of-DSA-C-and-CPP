#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<vector<int>, vector<string>> map;
    for (string &s : strs)
    {
        vector<int> count(26, 0);
        for (char c : s)
        {
            count[c - 'a']++;
        }
        map[count].push_back(s);
    }

    vector<vector<string>> ans;

    for (auto s : map)
    {
        ans.push_back(s.second);
    }
    return ans;
}
int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = groupAnagrams(strs);
    for(const auto& i : ans){
        for(const auto& j : i){
            cout<< j << " ";
        }
    }
    cout<<endl;
    return 0;
}