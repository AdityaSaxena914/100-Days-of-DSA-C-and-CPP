#include <bits/stdc++.h>
using namespace std;

int smallestSubarray(vector<int> &nums, int n, int k) {
    // Check for negative numbers
    for (int num : nums) {
        if (num < 0) {
            cout << "Array should not contain negative numbers." << endl;
            return -1;
        }
    }

    int start = 0, currentSum = 0, minimum = INT_MAX;

    for (int i = 0; i < n; i++) {
        currentSum += nums[i];

        // Shrink the window while the sum is >= k
        while (currentSum >= k) {
            minimum = min(minimum, i - start + 1);
            currentSum -= nums[start++];
        }
    }
    return (minimum == INT_MAX) ? -1 : minimum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter size of array: "<<endl;
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be greater than 0." << endl;
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter elements: "<<endl;
    for (int i = 0; i < n; i++) cin >> nums[i];

    int k;
    cout << "\nEnter the sum: "<<endl;
    cin >> k;

    if (k <= 0) {
        cout << "Sum must be greater than 0." << endl;
        return 0;
    }

    int result = smallestSubarray(nums, n, k);

    if (result != -1)
        cout << "Smallest subarray of sum " << k << " is " << result << endl;
    else
        cout << "No subarray with sum " << k << " is present" << endl;

    return 0;
}
