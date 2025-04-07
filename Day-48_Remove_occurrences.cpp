#include<bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {
    while(s.length() > 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main(){
    string s = "aabbccabcabcabababcacbabc";
    string part = "abc";
    string result = removeOccurrences(s, part);
    cout<<result<<endl;

return 0;
}