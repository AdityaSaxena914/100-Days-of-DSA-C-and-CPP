#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }
    unordered_map<char, int> map;
    for (char ch : s)
    {
        map[ch]++;
    }

    for (char ch : t)
    {
        if (map[ch] == 0)
        {
            return false;
        }
        map[ch]--;
    }
    return true;
}
int main()
{

    string s = "anagram";
    string t = "nagaram";
    if(isAnagram(s,t)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}