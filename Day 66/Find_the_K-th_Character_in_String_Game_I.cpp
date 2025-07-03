#include <bits/stdc++.h>
using namespace std;
char kthCharacter(int k)
{
    string sb = "a";
    while (sb.length() < k)
    {
        int size = sb.length();
        for (int i = 0; i < size; ++i)
        {
            char nextChar = 'a' + ((sb[i] - 'a' + 1) % 26);
            sb += nextChar;
        }
    }
    return sb[k - 1];
}
int main()
{
    int k;
    cin >> k;
    if (k <= 0)
    {
        cout << "Invalid input. k must be a positive integer." << endl;
        return 1;
    }
    char result = kthCharacter(k);
    cout << result << endl;

    return 0;
}