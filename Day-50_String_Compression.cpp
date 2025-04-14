#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int idx = 0;
    for(int i = 0; i<n;){
        char ch = chars[i];
        int count = 0;
        while(i < n && chars[i]==ch){
            count++;
            i++;
        }
        if(count == 1){
            chars[idx++] = ch;
        }
        else{
            chars[idx++] = ch;
            string str = to_string(count);
            for(auto dig : str){
                chars[idx++] = dig;
            }

        }
    }
    chars.resize(idx);
    return idx;
}

int main(){
vector<char> chars = {'a','a','a','b','b','b','b','c','c','c',};
int result = compress(chars);
for(auto res : chars){
    cout<< res<<" ";
}
cout<<endl;
return 0;
}