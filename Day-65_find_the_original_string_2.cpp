#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int possibleStringCount(string word, int k) {
    if (word.empty()) return 0;

    // Step 1: Group consecutive same characters
    vector<int> groups;
    int count = 1;

    for (size_t i = 1; i < word.size(); ++i) {
        if (word[i] == word[i - 1]) {
            count++;
        } else {
            groups.push_back(count);
            count = 1;
        }
    }
    groups.push_back(count); // Push the last group

    // Step 2: Total combinations (no restriction on k)
    long long total = 1;
    for (int num : groups) {
        total = (total * num) % MOD;
    }

    // Step 3: If enough characters already, return total
    if (k <= (int)groups.size()) return total;

    // Step 4: DP to count invalid combinations (length < k)
    vector<int> dp(k, 0);
    dp[0] = 1;

    for (int num : groups) {
        vector<int> newDp(k, 0);
        long long sum = 0;

        for (int s = 0; s < k; ++s) {
            if (s > 0)
                sum = (sum + dp[s - 1]) % MOD;

            if (s > num)
                sum = (sum - dp[s - num - 1] + MOD) % MOD;

            newDp[s] = sum;
        }

        dp = newDp;
    }

    // Step 5: Count invalid ways (length < k)
    long long invalid = 0;
    for (int s = groups.size(); s < k; ++s) {
        invalid = (invalid + dp[s]) % MOD;
    }

    // Step 6: Return valid ways
    return (total - invalid + MOD) % MOD;
}

int main() {
    // Sample test cases
    cout << possibleStringCount("aabbccdd", 7) << endl; // Output: 5
    cout << possibleStringCount("aabbccdd", 8) << endl; // Output: 1
    cout << possibleStringCount("aaabbb", 3) << endl;   // Output: 8

    return 0;
}