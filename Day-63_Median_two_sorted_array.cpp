#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    double median;
    vector<int> nums3;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            nums3.push_back(nums1[i++]);
        }
        else
        {
            nums3.push_back(nums2[j++]);
        }
    }

    while (i < m)
    {
        nums3.push_back(nums1[i++]);
    }
    while (j < n)
    {
        nums3.push_back(nums2[j++]);
    }
    int a = nums3.size();
    if (a % 2 == 1)
    {
        median = nums3[a / 2];
    }
    else
    {
        median = (nums3[a / 2 - 1] + nums3[a / 2]) / 2.0;
    }
    return median;
}
int main()
{

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double result = findMedianSortedArrays(nums1, nums2);
    cout << result << endl;

    return 0;
}