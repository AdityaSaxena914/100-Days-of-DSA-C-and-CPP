#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int N, int C, int minAlloweddistance)
{
    int cows = 1, laststallpos = arr[0];

    for (int i = 0; i < N; i++)
    { // O(n)
        if (arr[i] - laststallpos >= minAlloweddistance)
        {
            cows++;
            laststallpos = arr[i];
            
        }

        if (cows == C)
        {
            return true;
        }
    }

    return false;
}

int getDistance(vector<int> &arr, int N, int C)
{ // O(NlogN)
    sort(arr.begin(), arr.end());

    int ans = -1;
    int st = 1, end = arr[N-1] -arr[0]; // range of possible answer

    while (st <= end) // O(log(Range) * N)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, N, C, mid))
        { 
            ans = mid;
            st = mid + 1; // right
        }
        else
        {// left
            end = mid - 1;
            
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1,2,8,4,9};
    int N = 5, C = 3;
    cout << getDistance(arr, N, C) << endl;
    return 0;
}