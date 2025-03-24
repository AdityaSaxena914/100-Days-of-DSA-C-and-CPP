#include <bits/stdc++.h>
using namespace std;

int peakIndex(vector<int> &arr)
{
    int st = 1, end = arr.size() - 2;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

void insert(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

int main(){
    int n;
    cout<<"Size of array: ";
    cin>>n;

    vector<int> arr(n);
    insert(arr);

    int result = peakIndex(arr);
    cout<<"Peak index is: "<<result<<endl;
    return 0;
}