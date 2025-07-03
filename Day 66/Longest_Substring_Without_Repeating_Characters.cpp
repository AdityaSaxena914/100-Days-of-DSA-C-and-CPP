#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> lastSeen;
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.length(); right++)
    {
        char ch = s[right];

        if (lastSeen.count(ch) && lastSeen[ch] >= left)
        {
            left = lastSeen[ch] + 1;
        }

        lastSeen[ch] = right;

        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    if (s.empty())
    {
        cout << "Invalid input. The string must not be empty." << endl;
        return 1;
    }
    int result = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}