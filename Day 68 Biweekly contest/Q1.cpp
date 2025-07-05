#include <bits/stdc++.h>
using namespace std;
string intoBase(int num, int base)
{
    string ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    while (num > 0)
    {
        result = ch[num % base] + result;
        num /= base;
    }
    return result;
}
string concatHex36(int n)
{
    int square = n * n;
    int cube = n * n * n;
    string hexadec = intoBase(square, 16);
    string hexatri = intoBase(cube, 36);
    return hexadec + hexatri;
}
int main()
{
    int k;
    cin>>k;
    string res = concatHex36(k);
    cout<<res<<endl;

    return 0;
}
