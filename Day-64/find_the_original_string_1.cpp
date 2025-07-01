#include <bits/stdc++.h>
using namespace std;
int possibleStringCount(string word)
{
    int count = 0;
    char prev = ' ';

    for (char ch : word)
    {
        if (ch == prev)
        {
            count++;
        }
        prev = ch;
    }
    return count + 1;
}
int main()
{
    string word = "abacaba";
    int result = possibleStringCount(word);
    cout << result << endl;
    return 0;
}