#include <bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> idx;
    for (int i : nums)
    {
        idx[i]++;
        if (idx[i] == 2)
        {
            return true;
        }
    }
    return false;
}
int main()
{

    vector<int> nums = {1, 2, 3, 1};
    if (containsDuplicate(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}