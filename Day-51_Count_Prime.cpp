#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
            for (int j = i * 2; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return count;
}

int main(){
int n = 1284634;
int res = countPrimes(n);
cout<< res<<endl;
return 0;
}