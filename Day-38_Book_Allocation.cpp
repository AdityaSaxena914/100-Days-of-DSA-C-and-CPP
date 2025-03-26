#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages){
    int students = 1, pages = 0;

    for(int i = 0; i<n; i++){ // O(n)
        if(arr[i] > maxAllowedPages){
            return false;
        }

        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }else{
            students++;
            pages = arr[i];
        }
    }

    return students > m? false:true;
}
int allocateBook(vector<int>& arr, int n, int m){//O(logN * n)
    if(m>n){
        return -1;
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++)// O(n)
    {
        sum += arr[i];
    }
    int ans = -1;
    int st = 0, end = sum;// range of possible answer

    while (st <= end)// O(logN)
    {
        int mid = st + (end - st)/2;

        if(isValid(arr,n,m,mid)){//left
            ans = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;//right
        }
    }
    return ans;
}
int main(){
vector<int> arr = {15,17,20};
int n = 3, m=2;
cout<<allocateBook(arr,n,m)<<endl;
return 0;
}