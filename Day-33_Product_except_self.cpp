#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums)
{

    int n = nums.size();
    vector<int> answer(n, 1);

    // calculating prefix and storing it to answer array O(n)
    for (int i = 1; i < n; i++)
    {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    int suffix =1;

    // calculating suffix and adding to answer array O(n)
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= nums[i+1];
        answer[i] *= suffix;
    }

    return answer; // space complexcity O(n)
}
// Function to insert elements into the array
void insert(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    insert(nums);
    vector<int> result = twoSum(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}