#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedtime)
{
    int painter = 1, time = 0;

    for (int i = 0; i < n; i++)
    { // O(n)
        if (arr[i] > maxAllowedtime)
        {
            return false;
        }

        if (time + arr[i] <= maxAllowedtime)
        {
            time += arr[i];
        }
        else
        {
            painter++;
            time = arr[i];
        }
    }

    return painter <= m;
}
int minTimetoPaint(vector<int> &arr, int n, int m)
{ // O(logN * n) (N = sum)
    if (m > n)
    {
        return -1;
    }

    int sum = 0, maxVal = INT_MIN;
    for (int i = 0; i < n; i++) // O(n)
    {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }
    int ans = -1;
    int st = maxVal, end = sum; // range of possible answer

    while (st <= end) // O(logN)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, m, mid))
        { // left
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1; // right
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {40, 30, 10, 20};
    int n = 4, m = 2;
    cout << minTimetoPaint(arr, n, m) << endl;
    return 0;
}