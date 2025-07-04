#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int l = 0, r = 0, minLen = INT_MAX, sIndex = -1, count = 0;

    int hash[256] = {0};
    for (int i = 0; i < m; i++)
    {
        hash[t[i]]++;
    }
    while (r < n)
    {
        if (hash[s[r]] > 0)
        {
            count++;
        }
        hash[s[r]]--;
        while (count == m)
        {
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                sIndex = l;
            }
            hash[s[l]]++;
            if (hash[s[l]] > 0)
            {
                count--;
            }
            l++;
        }
        r++;
    }
    return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = minWindow(s, t);
    if (result.empty())
    {
        cout << "No valid window found." << endl;
    }
    else
    {
        cout << "Minimum window substring is: " << result << endl;
    }
    return 0;
}