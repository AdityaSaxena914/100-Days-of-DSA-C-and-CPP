#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    int a = INT_MAX, b = INT_MAX;
    if (nums.size() < 3)
    {
        return false;
    }
    for (auto idx : nums)
    {
        if (idx <= a)
        {
            a = idx;
            ;
        }
        else if (idx <= b)
        {
            b = idx;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{

    vector<int> nums = {2,1,5,0,4,6};
    if(increasingTriplet(nums)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    

    return 0;
}