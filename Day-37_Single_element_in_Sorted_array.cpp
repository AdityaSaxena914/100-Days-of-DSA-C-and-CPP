#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& A) {
    int n = A.size();
    int st = 0, end = n-1;

    if(n == 1){
        return A[0];
    }

    while(st<=end){
        int mid = st + (end - st)/2;

        if(mid == 0 && A[0]!=A[1]){
            return A[mid];
        }
        if(mid == n-1 && A[n-1] != A[n-2]){
            return A[mid];
        }

        if(A[mid-1] != A[mid] && A[mid] != A[mid+1]){
            return A[mid];
        }
        else if(mid % 2 == 0){
            if(A[mid] == A[mid - 1]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
           
        }
        else{
            if(A[mid] == A[mid - 1]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    return -1;        
}
void insert(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}
int main(){
int n;
cout<<"Array size: ";
cin>>n;
vector<int> A (n);
insert(A);
int result = singleNonDuplicate(A);
cout<<"Element: "<<result<<endl;
return 0;
}