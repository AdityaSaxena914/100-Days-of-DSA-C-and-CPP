#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &a, int t)
{
    int st = 0, end = a.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (a[mid] < t)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return st;
}

vector<int> searchRange(vector<int> &a, int t)
{
    int first_occurence = firstOcc(a, t);
    int Last_occurence;
    int n = a.size();

    if (n == 1 && a[0] == t)
    {
        return {0, 0};
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == t)
        {
            Last_occurence = i;
            return {first_occurence, Last_occurence};
        }
    }

    return {-1, -1};
}
int main()
{

    vector<int> a = {5,7,7,8,8,10};
    int target;
    cin>>target;
    vector<int> result = searchRange(a,target);

    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}